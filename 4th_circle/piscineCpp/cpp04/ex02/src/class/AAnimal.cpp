/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:45:09 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 16:24:30 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "AAnimal.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
AAnimal::AAnimal( void ) : _type( "random animal" ) {

	std::cout << _type << ": default constructor called." << std::endl;

	_brain = new Brain();
}

AAnimal::AAnimal( std::string type ) : _type( type ) {

	std::cout << "Random animal: string constructor called for " << _type << "." << std::endl;

	_brain = new Brain( _type );
}

AAnimal::AAnimal( AAnimal const & src ) : _type( src._type ) {

	std::cout << "Random animal: copy constructor called for " << _type << "." <<std::endl;

	_brain = new Brain( src._type );
}

AAnimal::~AAnimal( void ) {

	std::cout << "Random animal: default destructor called." << std::endl;

	delete _brain;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
AAnimal&	AAnimal::operator=( AAnimal const & rhs ) {

	if ( this != &rhs ) {

		_type = rhs._type;
	}

	return *this;
}

void	AAnimal::printIdeas( void ) const {

	this->_brain->printIdeas();
}

/******************************************************************************/
/*   GETTERS                                                                  */
/******************************************************************************/
std::string	AAnimal::getType( void ) const {

	return _type;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	AAnimal::makeSound( void ) const {

	std::cout << _type << ": animal !" << std::endl;
}

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, AAnimal const & rhs ) {

	o << "AAnimal type = " << rhs.getType();

	return o;
}
