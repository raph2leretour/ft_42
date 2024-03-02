/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:16:44 by rtissera          #+#    #+#             */
/*   Updated: 2024/03/02 17:32:10 by rtissera         ###   ########.fr       */
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

		if ( src._source[ i ] ) {

			_source[ i ] = src._source[ i ]->clone();
		}
		else {

			_source[ i ] = NULL;
		}
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

	if ( this != &rhs ) {

		for ( int i = 0; i < 4; i++ ) {

			if ( _source[ i ] ) {

				delete _source[ i ];
			}
			if ( rhs._source[ i ] ) {

				_source[ i ] = rhs._source[ i ]->clone();
			}
			else {

				_source[ i ] = NULL;
			}
		}
	}

	return *this;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	MateriaSource::learnMateria( AMateria* src ) {

	if ( !src ) {

		return ;
	}
	for ( int i = 0; i < 4; i++ ) {

		if ( !_source[ i ] ) {

			_source[ i ] = src;

			return ;
		}
	}
	delete src;
}

AMateria*	MateriaSource::createMateria( std::string const & type ) {

	for ( int i = 0; i < 4; i++ ) {

		if ( _source[ i ] && _source[ i ]->getType() == type ) {

			return _source[ i ]->clone();
		}
	}

	return NULL;
}
