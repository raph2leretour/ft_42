/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:52:08 by rtissera          #+#    #+#             */
/*   Updated: 2024/07/26 18:13:03 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main( void ) {

	try {

		Bureaucrat b1( "Pablo", 1 );
		std::cout << b1;
		b1.incrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b2;
		std::cout << b2;
		b2.decrementGrade();
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b3("Pedro", 160);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		Bureaucrat b4("Hildegarde", -5);
	} catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
