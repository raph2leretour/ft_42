/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:30:38 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/21 16:31:12 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
# include <iostream>

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Fixed {

private:
	int			_fixedPointValue;
	static int const	_fractionalBits = 8;

public:
	Fixed( void );
	Fixed( int const n );
	Fixed( float const n );
	Fixed( Fixed const & src );
	~Fixed( void );

	Fixed&			operator=( Fixed const & rhs );

	Fixed			operator+( Fixed const & rhs ) const;
	Fixed			operator-( Fixed const & rhs ) const;
	Fixed			operator*( Fixed const & rhs ) const;
	Fixed			operator/( Fixed const & rhs ) const;

	bool			operator>( Fixed const & rhs ) const;
	bool			operator<( Fixed const & rhs ) const;
	bool			operator>=( Fixed const & rhs ) const;
	bool			operator<=( Fixed const & rhs ) const;
	bool			operator==( Fixed const & rhs ) const;
	bool			operator!=( Fixed const & rhs ) const;

	Fixed&			operator++( void );
	Fixed			operator++( int );
	Fixed&			operator--( void );
	Fixed			operator--( int );

	static Fixed&		min( Fixed& lhs, Fixed& rhs );
	static Fixed const &	min( Fixed const & lhs, Fixed const & rhs );
	static Fixed&		max( Fixed& lhs, Fixed& rhs );
	static Fixed const &	max( Fixed const & lhs, Fixed const & rhs );

	int			getRawBits( void ) const;
	void			setRawBits( int const raw );

	float			toFloat( void ) const;
	int			toInt( void ) const;

};

std::ostream&			operator<<( std::ostream& o, Fixed const & rhs );
