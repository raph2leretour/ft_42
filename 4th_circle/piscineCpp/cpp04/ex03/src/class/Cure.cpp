/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:05:32 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/26 19:07:02 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Cure.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Cure::Cure( void ) : AMateria( "cure" ) {

	std::cout << "Cure: default constructor called" << std::endl;
}

Cure::Cure( Cure const & src ) : AMateria( src ) {

	std::cout << "Cure: default constructor called from " << src._type << std::endl;

	*this = src;
}

Cure::~Cure( void ) {

	std::cout << "Cure: default constructor called" << std::endl;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Cure&	Cure::operator=( Cure const & rhs ) {

	if ( this != &rhs ) {

		_type = rhs._type;
	}

	return *this;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
AMateria*	clone( void ) const {

	AMateria*	newCure = Cure( this );

	return newCure;
}

void	use( ICharacter& target ) {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
