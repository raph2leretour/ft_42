/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 10:48:01 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/21 17:07:05 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << --a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a = " << a-- << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << "min is " << Fixed::min( a, b ) << std::endl;
	std::cout << "max is " << Fixed::max( a, b ) << std::endl;

	if ( a < b ) {

		std::cout << "a < b" << std::endl;
	} else {

		std::cout << "a > b" << std::endl;
	}
	if ( a > b ) {

		std::cout << "a > b" << std::endl;
	} else {

		std::cout << "a < b" << std::endl;
	}
	if ( a <= b ) {

		std::cout << "a <= b" << std::endl;
	} else {

		std::cout << "a > b" << std::endl;
	}
	if ( a >= b ) {

		std::cout << "a >= b" << std::endl;
	} else {

		std::cout << "a < b" << std::endl;
	}
	if ( a != b ) {

		std::cout << "a != b" << std::endl;
	} else {

		std::cout << "a == b" << std::endl;
	} if ( a == b ) {

		std::cout << "a == b" << std::endl;
	} else {

		std::cout << "a != b" << std::endl;
	}

	a = 4;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	a = b * 4;
	std::cout << "a = " << a << std::endl;
	a = b / 4;
	std::cout << "a = " << a << std::endl;
	a = b + 4;
	std::cout << "a = " << a << std::endl;
	a = b - 4;
	std::cout << "a = " << a << std::endl;

	return 0;
}
