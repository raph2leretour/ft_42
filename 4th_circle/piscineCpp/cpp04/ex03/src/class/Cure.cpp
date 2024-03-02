/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:05:32 by rtissera          #+#    #+#             */
/*   Updated: 2024/03/02 16:33:48 by rtissera         ###   ########.fr       */
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

Cure::Cure( Cure const & src ) : AMateria( "cure" ) {

	std::cout << "Cure: default constructor called" << std::endl;

	( void )src;
}

Cure::~Cure( void ) {

	std::cout << "Cure: default constructor called" << std::endl;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Cure&	Cure::operator=( Cure const & rhs ) {

	( void )rhs;

	return *this;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
AMateria*	Cure::clone( void ) const {

	return new Cure( *this );
}

void	Cure::use( ICharacter& target ) {

	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
