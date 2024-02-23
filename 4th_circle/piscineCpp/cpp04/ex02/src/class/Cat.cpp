/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:39:32 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 20:00:56 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Cat.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Cat::Cat( void ) : AAnimal( "Cat" ) {

	std::cout << _type << ": default constructor called." << std::endl;

	_brain = new Brain( "Cat" );
}

Cat::Cat( Cat const & src ) : AAnimal( src ) {

	std::cout << _type << ": copy constructor called." << std::endl;

	_type = src._type;
	_brain = new Brain( "Cat" );
}

Cat::~Cat( void ) {

	std::cout << _type << ": default destructor called." << std::endl;

	delete _brain;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Cat&	Cat::operator=( Cat const & rhs ) {

	if ( this != &rhs ) {

		_type = rhs._type;
	}

	return *this;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	Cat::makeSound( void ) const {

	std::cout << _type << ": miaou !" << std::endl;
}

void	Cat::printIdeas( void ) const {

	this->_brain->printIdeas();
}
