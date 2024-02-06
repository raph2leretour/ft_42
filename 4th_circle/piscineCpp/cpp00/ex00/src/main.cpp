/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:49:00 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/06 17:55:44 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( int argc, char **argv ) {

	if ( argc > 1 ) {

		for ( int i = 1; argv[ i ]; i++ ) {

			std::string	s = argv[ i ];
			for ( std::string::iterator it = s.begin(); it != s.end(); it++ ) {

				char	c = *it;
				std::cout << ( char )toupper( c );
			}
		}
	} else {

		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;

	return 0;
}
