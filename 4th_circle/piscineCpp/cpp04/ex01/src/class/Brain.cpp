/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 12:19:58 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/22 16:13:45 by rtissera         ###   ########.fr       */
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

	for ( int i = 0; i < 100; i++ ) {

		_ideas[ i ] = "animal !";
	}

	std::cout << "Brain: default constructor called" << std::endl;
}

Brain::Brain( std::string idea ) {

	for ( int i = 0; i < 100; i++ ) {

		_ideas[ i ] = idea;
	}

	std::cout << "Brain: string constructor called" << std::endl;
}

Brain::Brain( Brain const & src ) {

	*this = src;

	std::cout << "Brain: copy constructor called" <<std::endl;
}

Brain::~Brain( void ) {

	std::cout << "Brain: default destructor called" << std::endl;
}

/******************************************************************************/
/*   GETTERS                                                                  */
/******************************************************************************/
std::string*	getIdeas( void ) const {

	return _ideas;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Brain&	Brain::operator=( Brain const & rhs ) {

	for ( int i = 0; i < 100; i++ ) {

		_ideas[ i ] = rhs._ideas[ i ];
	}

	return *this;
}

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, Brain const & rhs ) {

	std::string	*idea = rhs.getIdeas();

	for ( int i = 0; i < 100; i++ ) {

		o << idea[ i ] << std::endl;
	}

	return o;
}
