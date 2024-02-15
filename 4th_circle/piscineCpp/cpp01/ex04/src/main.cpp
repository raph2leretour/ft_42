/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:21:11 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/15 19:34:31 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>

std::string	getFile( std::ifstream ifs ) {

	std::string	file;

	while ( !ifs.eof ) {

		getline( ifs, file );
	}
	return file;
}

std::string	replace( std::string file ) {}

int	main( int argc, char ** argv ) {

	if ( argc == 3 ) {

		std::ifstream	ifs( argv[ 1 ] );
		if ( !ifs.is_open() ) {

			std::cout << "Error opening file" << std::endl;
		}
		std::string	file = getFile( ifs );
		ifs.close();
		file = replace( file );
	}
	return 0;
}
