/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:45:50 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/25 18:38:02 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "AMateria.hpp"
#include "ICharacter.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
AMateria::AMateria( void ) : _type( "undefind materia" ) {

	std::cout << "Undefined materia: default constructor called" << std::endl;
}

AMateria::AMateria( AMateria const & src ) : _type( src._type ) {

	std::cout << "Undefined materia: copy constructor called from " << src._type << std::endl;
}

AMateria::~AMateria( void ) {

	std::cout << "Undefined materia: default destructor called" << std::endl;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
AMateria&	AMateria::operator=( AMateria const & rhs ) {

	if ( this != &rhs ) {

		_type = rhs._type;
	}

	return *this;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
std::string	AMateria::getType( void ) const {

	return _type;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	AMateria::use( ICharacter& target ) {

	std::cout << "* coughing at " << target.getName() << " *" << std::endl;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
std::ostream&		operator<<( std::ostream& o, AMateria const & rhs ) {

	o << "Type = " << _type;

	return o;
}
