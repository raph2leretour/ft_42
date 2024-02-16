/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 14:21:11 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/16 19:41:57 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main( int argc, char ** argv ) {

	if ( argc == 4 && argv[ 2 ] && argv[ 2 ][ 0 ]) {

		std::ifstream	ifs( argv[ 1 ] );
		if ( !ifs.is_open() || ifs.fail() ) {

			std::cout << "Error opening infile" << std::endl;
			return -1;
		}

		std::ofstream	ofs( ( std::string( argv[ 1 ] ) + ".replace" ).c_str() );
		if ( !ofs.is_open() ) {

			std::cout << "Error opening outfile" << std::endl;
		}

		std::string	line;
		std::string	s1 = argv[ 2 ];
		std::string	s2 = argv[ 3 ];
		while ( !ifs.eof() ) {

			getline( ifs, line );
			line += "\n";

			size_t	pos = 0;
			while ( ( pos = line.find( s1, pos ) ) != line.npos ) {

				line.erase( pos, s1.length() );
				line.insert( pos, s2 );

				pos += s2.length();
			}

			ofs << line << std::endl;
		}

		ifs.close();
		ofs.close();
	}
	return 0;
}
