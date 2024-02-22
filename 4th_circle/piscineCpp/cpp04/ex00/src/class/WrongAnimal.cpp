/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:54:50 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/22 13:20:08 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "WrongAnimal.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
WrongAnimal::WrongAnimal( void ) : _type( "wrong random animal" ) {

	std::cout << _type << ": default contructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src ) : _type( src._type ) {

	std::cout << _type << ": copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {

	std::cout << _type << ": default destructor called" << std::endl;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
WrongAnimal&	WrongAnimal::operator=( WrongAnimal const & rhs ) {

	_type = rhs._type;

	return *this;
}

/******************************************************************************/
/*   GETTERS                                                                  */
/******************************************************************************/
std::string	WrongAnimal::getType( void ) const {

	return _type;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	WrongAnimal::makeSound( void ) const {

	std::cout << _type << ": wrong animal !" << std::endl;
}

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, WrongAnimal const & rhs ) {

	o << "Type = " << rhs.getType();

	return o;
}
