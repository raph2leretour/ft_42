/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:04:01 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 20:51:29 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Brain.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Brain::Brain( void ) {

	std::cout << "Brain: default constructor called." << std::endl;

	for ( int i = 0; i < 100; i++ ) {

		_ideas[ i ] = "*Random animal though*";
	}
}

Brain::Brain( std::string idea ) {

	std::cout << "Brain: string constructor called for " << idea << "." << std::endl;

	for ( int i = 0; i < 100; i++ ) {

		_ideas[ i ] = "*";
		_ideas[ i ] += idea;
		_ideas[ i ] += " though*";
	}
}

Brain::Brain( Brain const & src ) {

	std::cout << "Brain: copy constructor called for " << src._ideas[ 0 ] << "." <<std::endl;

	for ( int i = 0; i < 100; i++ ) {

		_ideas[ i ] = src._ideas[ i ];
	}
}

Brain::~Brain( void ) {

	std::cout << "Brain: default destructor called." << std::endl;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Brain&	Brain::operator=( Brain const & rhs ) {

	if ( this != &rhs ) {

		for ( int i = 0; i < 100; i++ ) {
			_ideas[ i ] = rhs._ideas[ i ];
		}
	}

	return *this;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	Brain::printIdeas( void ) const {

	for ( int i = 0; i < 100; i++ ) {

		std::cout << _ideas[ i ] << std::endl;
	}
}
