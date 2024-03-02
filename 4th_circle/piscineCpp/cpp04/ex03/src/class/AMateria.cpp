/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:45:50 by rtissera          #+#    #+#             */
/*   Updated: 2024/03/02 16:31:57 by rtissera         ###   ########.fr       */
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
AMateria::AMateria( void ) : _type( "Cannot create typeless materia" ) {}

AMateria::AMateria( std::string const & type ) : _type( type ) {

	std::cout << "Undefined materia: string constructor called" << std::endl;
}

AMateria::AMateria( AMateria const & src ) : _type( src._type ) {

	std::cout << "Undefined materia: copy constructor called" << std::endl;
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
/*   ACCESSORS                                                                */
/******************************************************************************/
std::string const &	AMateria::getType( void ) const {

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

	o << "Type = " << rhs.getType();

	return o;
}
