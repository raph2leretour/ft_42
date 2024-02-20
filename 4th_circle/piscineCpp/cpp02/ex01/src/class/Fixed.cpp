/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:48:34 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/20 23:00:05 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : _fixedPointValue( 0 ) {

	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed( int const n ) : _fixedPointValue( n << _fractionalBits ) {

	std::cout << "Int Constructor called" << std::endl;
}

Fixed::Fixed( float const n ) : _fixedPointValue( roundf( n * ( 1 << _fractionalBits ) ) ) {

	std::cout << "Float Constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) : _fixedPointValue( src._fixedPointValue ) {

	std::cout << "Copy Constructor called" << std::endl;
}

Fixed::~Fixed( void ) {

	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=( Fixed const & rhs ) {

	std::cout << "Copy assignment operator called" << std::endl;

	if ( this != &rhs ) {

		this->_fixedPointValue = rhs._fixedPointValue;
	}

	return *this;
}

int	Fixed::getRawBits( void ) const {

	std::cout << "getRawBits member function called" << std::endl;

	return this->_fixedPointValue;
}

void	Fixed::setRawBits( int const raw ) {

	std::cout << "setRawBits member function called" << std::endl;

	this->_fixedPointValue = raw;
}

float	Fixed::toFloat( void ) const {

	return this->_fixedPointValue / ( float )( 1 << _fractionalBits );
}

int	Fixed::toInt( void ) const {

	return this->_fixedPointValue >> _fractionalBits;
}

std::ostream &	operator<<( std::ostream& o, Fixed const & rhs ) {

	o << rhs.toFloat();

	return o;
}
