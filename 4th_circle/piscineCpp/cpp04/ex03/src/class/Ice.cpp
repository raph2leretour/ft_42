/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:59:41 by rtissera          #+#    #+#             */
/*   Updated: 2024/03/02 16:33:56 by rtissera         ###   ########.fr       */
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

Ice::Ice( Ice const & src ) : AMateria( "ice" ) {

	std::cout << "Ice: copy constructor called" << std::endl;

	( void )src;
}

Ice::~Ice( void ) {

	std::cout << "Ice: default destructor called" << std::endl;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Ice&	Ice::operator=( Ice const & rhs ) {

	( void )rhs;

	return *this;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
AMateria*	Ice::clone( void ) const {

	return new Ice( *this );
}

void	Ice::use( ICharacter& target ) {

	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
