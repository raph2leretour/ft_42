/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:54:50 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 13:34:10 by rtissera         ###   ########.fr       */
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

	std::cout << _type << ": default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type ) {

	std::cout << "Wrong random animal: " << _type << ": string constructor called." << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src ) : _type( src._type ) {

	std::cout << "Wrong random animal: " << _type << " copy constructor called." << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {

	std::cout << "Wrong random animal: default destructor called." << std::endl;
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

	o << "Wrong animal type = " << rhs.getType();

	return o;
}
