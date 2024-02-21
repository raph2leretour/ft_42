# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
#                                                     +:+ +:+         +:+      #
#    By: rtissera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/21 16:33:00 by rtissera          #+#    #+#              #
/*   Updated: 2024/02/21 16:34:37 by rtissera         ###   ########.fr       */
#                                                                              #
# **************************************************************************** #

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Fixed.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Fixed::Fixed( void ) : _fixedPointValue( 0 ) {}

Fixed::Fixed( Fixed const & src ) : _fixedPointValue( src._fixedPointValue ) {}

Fixed::~Fixed( void ) {}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
Fixed&	Fixed::operator=( Fixed const & rhs ) {

	if ( this != &rhs ) {

		this->_fixedPointValue = rhs._fixedPointValue;
	}

	return *this;
}

/******************************************************************************/
/*   ARITHMETIC OPERATORS                                                     */
/******************************************************************************/
Fixed	Fixed::operator+( Fixed const & rhs ) const {

	return Fixed( this->toFloat()+ rhs.toFloat());
}

Fixed	Fixed::operator-( Fixed const & rhs ) const {

	return Fixed( this->toFloat()- rhs.toFloat());
}

Fixed	Fixed::operator*( Fixed const & rhs ) const {

	return Fixed( this->toFloat()* rhs.toFloat());
}

Fixed	Fixed::operator/( Fixed const & rhs ) const {

	return Fixed( this->toFloat()/ rhs.toFloat());
}

/******************************************************************************/
/*   COMPARISON OPERATORS                                                     */
/******************************************************************************/
bool	Fixed::operator>( Fixed const & rhs ) const {

	return this->_fixedPointValue > rhs._fixedPointValue;
}

bool	Fixed::operator<( Fixed const & rhs ) const {

	return this->_fixedPointValue < rhs._fixedPointValue;
}

bool	Fixed::operator>=( Fixed const & rhs ) const {

	return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool	Fixed::operator<=( Fixed const & rhs ) const {

	return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool	Fixed::operator==( Fixed const & rhs ) const {

	return this->_fixedPointValue == rhs._fixedPointValue;
}

bool	Fixed::operator!=( Fixed const & rhs ) const {

	return this->_fixedPointValue != rhs._fixedPointValue;
}

/******************************************************************************/
/*   INCREMENT / DECREMENT OPERATORS                                          */
/******************************************************************************/
Fixed&	Fixed::operator++( void ) {

	++this->_fixedPointValue;

	return *this;
}

Fixed	Fixed::operator++( int ) {

	Fixed	tmp( *this );
	tmp._fixedPointValue = this->_fixedPointValue++;

	return tmp;
}

Fixed&	Fixed::operator--( void ) {

	--this->_fixedPointValue;

	return *this;
}

Fixed	Fixed::operator--( int ) {

	Fixed	tmp( *this );
	tmp._fixedPointValue = this->_fixedPointValue--;

	return tmp;
}

/******************************************************************************/
/*   MIN / MAX                                                                */
/******************************************************************************/

/******************************************************************************/
/*   GETTERS / SETTERS                                                        */
/******************************************************************************/

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/

/******************************************************************************/
/*   STREAM REDIRECTION OPERATOR                                              */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, Fixed const & rhs ) {

	o << rhs.toFloat();

	return o;
}
