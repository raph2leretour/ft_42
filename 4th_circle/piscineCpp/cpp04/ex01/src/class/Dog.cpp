/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:18 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 20:53:23 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Dog.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Dog::Dog( void ) : Animal( "Dog" ) {

	std::cout << _type << ": default constructor called." << std::endl;

	_brain = new Brain( "Dog" );
}

Dog::Dog( Dog const & src ) : Animal( src ) {

	std::cout << _type << ": copy constructor called." << std::endl;

	_type = src._type;
	_brain = new Brain( "Dog" );
}

Dog::~Dog( void ) {

	std::cout << _type << ": default destructor called." << std::endl;

	delete _brain;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Dog&	Dog::operator=( Dog const & rhs ) {

	if ( this != &rhs ) {

		_type = rhs._type;
	}

	return *this;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	Dog::makeSound( void ) const {

	std::cout << _type << ": ouaf !" << std::endl;
}

void	Dog::printIdeas( void ) const {

	_brain->printIdeas();
}
