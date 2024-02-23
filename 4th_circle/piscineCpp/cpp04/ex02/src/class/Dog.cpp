/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:28:18 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 21:14:06 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Dog.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Dog::Dog( void ) : AAnimal( "Dog" ) {

	std::cout << _type << ": default constructor called." << std::endl;

	_brain = new Brain( "Dog" );
}

Dog::Dog( Dog const & src ) : AAnimal( src ) {

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
		_brain = new Brain( "Dog" );
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
