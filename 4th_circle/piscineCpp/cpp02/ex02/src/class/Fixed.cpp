/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:48:34 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/20 23:48:27 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "Fixed.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
Fixed::Fixed( void ) : _fixedPointValue( 0 ) {}

Fixed::Fixed( int const n ) : _fixedPointValue( n << _fractionalBits ) {}

Fixed::Fixed( float const n ) : _fixedPointValue( roundf( n * ( 1 << _fractionalBits ) ) ) {}

Fixed::Fixed( Fixed const & src ) : _fixedPointValue( src._fixedPointValue ) {}

Fixed::~Fixed( void ) {}

/******************************************************************************/
/*   ARITHMETIC OPERATORS                                                     */
/******************************************************************************/
Fixed&	Fixed::operator=( Fixed const & rhs ) {

	if ( this != &rhs ) {

		this->_fixedPointValue = rhs._fixedPointValue;
	}

	return *this;
}

Fixed	Fixed::operator+( Fixed const & rhs ) {

	return Fixed( this->_fixedPointValue + rhs->_fixedPointValue );
}

Fixed	Fixed::operator-( Fixed const & rhs ) {

	return Fixed( this->_fixedPointValue - rhs->_fixedPointValue );
}

Fixed	Fixed::operator*( Fixed const & rhs ) {

	return Fixed( this->_fixedPointValue * rhs->_fixedPointValue );
}

Fixed	Fixed::operator/( Fixed const & rhs ) {

	return Fixed( this->_fixedPointValue / rhs->_fixedPointValue );
}

/******************************************************************************/
/*   COMPARISON OPERATORS                                                     */
/******************************************************************************/
bool	Fixed::operator>( Fixed const & rhs ) const {

	return this->_fixedPointValue > rhs->_fixedPointValue;
}

bool	Fixed::operator<( Fixed const & rhs ) const {

	return this->_fixedPointValue < rhs->_fixedPointValue;
}

bool	Fixed::operator>=( Fixed const & rhs ) const {

	return this->_fixedPointValue >= rhs->_fixedPointValue;
}

bool	Fixed::operator<=( Fixed const & rhs ) const {

	return this->_fixedPointValue <= rhs->_fixedPointValue;
}

bool	Fixed::operator==( Fixed const & rhs ) const {

	return this->_fixedPointValue == rhs->_fixedPointValue;
}

bool	Fixed::operator!=( Fixed const & rhs ) const {

	return this->_fixedPointValue != rhs->_fixedPointValue;
}

/******************************************************************************/
/*   INCREMENT / DECREMENT OPERATORS                                          */
/******************************************************************************/
Fixed	Fixed::operator++( void ) const {

	return Fixed( this->_fixedPointValue + this->_fixedPointValue );
}

Fixed	Fixed::operator--( void ) const {

	return Fixed( this->_fixedPointValue + this->_fixedPointValue );
}

/******************************************************************************/
/*   STREAM REDIRECTION OPERATOR                                              */
/******************************************************************************/
std::ostream &	Fixed::operator<<( std::ostream& o, Fixed const & rhs ) {

	o << rhs.toFloat();

	return o;
}

/******************************************************************************/
/*   GETERS / SETERS                                                          */
/******************************************************************************/
int	Fixed::getRawBits( void ) const {

	return this->_fixedPointValue;
}

void	Fixed::setRawBits( int const raw ) {

	this->_fixedPointValue = raw;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
float	Fixed::toFloat( void ) const {

	return this->_fixedPointValue / ( float )( 1 << _fractionalBits );
}

int	Fixed::toInt( void ) const {

	return this->_fixedPointValue >> _fractionalBits;
}
