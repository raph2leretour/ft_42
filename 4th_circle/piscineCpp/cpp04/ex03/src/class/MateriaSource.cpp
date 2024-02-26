/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:16:44 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/26 19:52:12 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "MateriaSource.hpp"

/******************************************************************************/
/*   ACCESSORS                                                                */
/******************************************************************************/
MateriaSource::MateriaSource( void ) {

	stsd::cout << "MateriaSource: default constructor called" << std::endl;

	for ( int i = 0; i < 4; i++ ) {

		_source[ i ] = NULL;
	}
}

MateriaSource::MateriaSource( MateriaSource const & src ) {

	stsd::cout << "MateriaSource: copy constructor called" << std::endl;

	for ( int i = 0; i < 4; i++ ) {

		_source[ i ] = src._source[ i ];
	}
}

MateriaSource::~MateriaSource( void ) {

	stsd::cout << "MateriaSource: default destructor called" << std::endl;

	for ( int i = 0; i < 4; i++ ) {

		if ( _source[ i ] ) {

			delete _source[ i ];
		}
	}
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
MateriaSource&	MateriaSource::operator=( MateriaSource const & rhs ) {

	if ( this!= rhs ) {

		for ( int i = 0; i < 4; i++ ) {

			_source[ i ] = rhs._source[ i ];
		}
	}

	return *this;
}

/******************************************************************************/
/*   ACCESSORS                                                                */
/******************************************************************************/
AMateria*	MateriaSource::getSource( void ) const {

	return _source;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	MateriaSource::learnMateria( AMateria* src ) {}

AMateria*	MateriaSource::createMateria( std::string const & type ) {}

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, MateriaSource const & rhs ) {

	o << "MateriaSource = {";
	for ( int i = 0; i < 4; i++ ) {

		o << " " << i << ": rhs._source[ i ],;
	}
	o << " }";

	return o;
}
