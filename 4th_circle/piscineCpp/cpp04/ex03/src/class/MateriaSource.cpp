/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:16:44 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/27 18:59:01 by rtissera         ###   ########.fr       */
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

	std::cout << "MateriaSource: default constructor called" << std::endl;

	for ( int i = 0; i < 4; i++ ) {

		_source[ i ] = NULL;
	}
}

MateriaSource::MateriaSource( MateriaSource const & src ) {

	std::cout << "MateriaSource: copy constructor called" << std::endl;

	for ( int i = 0; i < 4; i++ ) {

		_source[ i ] = src._source[ i ];
	}
}

MateriaSource::~MateriaSource( void ) {

	std::cout << "MateriaSource: default destructor called" << std::endl;

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

	if ( this!= &rhs ) {

		for ( int i = 0; i < 4; i++ ) {

			if ( _source[ i ] ) {

				delete _source[ i ];
			}
			_source[ i ] = rhs._source[ i ];
		}
	}

	return *this;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	MateriaSource::learnMateria( AMateria* src ) {

	for ( int i = 0; i < 4; i++ ) {

		if ( !_source[ i ] ) {

			_source[ i ] = src;
		}
	}
}

AMateria*	MateriaSource::createMateria( std::string const & type ) {

	for ( int i = 0; i < 4; i++ ) {

		if ( _source[ i ]->getType() == type ) {

			return _source[ i ];
		}
	}

	return NULL;
}
