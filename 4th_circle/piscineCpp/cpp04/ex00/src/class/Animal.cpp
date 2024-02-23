/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 08:45:09 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 13:56:17 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Animal.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Animal::Animal( void ) : _type( "random animal" ) {

	std::cout << _type << ": default constructor called." << std::endl;
}

Animal::Animal( std::string type ) : _type( type ) {

	std::cout << "Random animal: string constructor called for " << _type << "." << std::endl;
}

Animal::Animal( Animal const & src ) : _type( src._type ) {

	std::cout << "Random animal: copy constructor called for " << _type << "." <<std::endl;
}

Animal::~Animal( void ) {

	std::cout << "Random animal: default destructor called." << std::endl;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Animal&	Animal::operator=( Animal const & rhs ) {

	if ( this != &rhs ) {

		_type = rhs._type;
	}

	return *this;
}

/******************************************************************************/
/*   GETTERS                                                                  */
/******************************************************************************/
std::string	Animal::getType( void ) const {

	return _type;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	Animal::makeSound( void ) const {

	std::cout << _type << ": animal !" << std::endl;
}

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, Animal const & rhs ) {

	o << "Animal type = " << rhs.getType();

	return o;
}
