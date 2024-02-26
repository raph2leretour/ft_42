/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:59:41 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/26 19:04:06 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Ice.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Ice::Ice( void ) : AMateria( "ice" ) {

	std::cout << "Ice: default constructor called" << std::endl;
}

Ice::Ice( Ice const & src ) : AMateria( src ) {

	std::cout << "Ice: copy constructor called from " << src._type << std::endl;

	*this = src;
}

Ice::~Ice( void ) {

	std::cout << "Ice: default destructor called" << std::endl;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Ice&	Ice::operator=( Ice const & rhs ) {

	if ( this != &rhs ) {

		_type = rhs._type;
	}

	return *this;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
AMateria*	clone( void ) const {

	AMateria*	newIce = Ice( this );

	return newIce;
}

void	use( ICharacter& target ) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
