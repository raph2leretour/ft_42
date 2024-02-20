/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:48:55 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/20 22:44:42 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
# include <iostream>
# include <cmath>

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

	Fixed &			operator=( Fixed const & rhs );

	int			getRawBits( void ) const;
	void			setRawBits( int const raw );

	float			toFloat( void ) const;
	int			toInt( void ) const;

};

std::ostream &			operator<<( std::ostream& o, Fixed const & rhs );
