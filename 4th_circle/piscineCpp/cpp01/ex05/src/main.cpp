/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 19:48:46 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/16 20:57:13 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main( void ) {

	std::cout << "Please enter a command: ";
	if ( !std::cin ) {

		exit( EXIT_SUCCESS );
	}
	std::string	value;
	std::getline( std::cin, value );
	if ( std::cin.eof() ) {

		exit( EXIT_SUCCESS );
	}

	Harl	harl;

	harl.complain( value );

	return 0;
}
