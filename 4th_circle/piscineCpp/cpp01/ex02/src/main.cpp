/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:18:20 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/09 19:26:46 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main( void ) {

	std::string	string = "HI THIS IS BRAIN";
	std::string*	stringPtr = &string;
	std::string&	stringREF = string;

	std::cout << &string << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	std::cout << string << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return 0;
}
