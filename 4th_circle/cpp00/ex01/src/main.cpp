/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:34:59 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/02 18:25:35 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {

	PhoneBook	phoneBook;
	std::string	command;

	phoneBook.initPhoneBook();
	std::cout << "Welcome to your PhoneBook!" << std::endl;
	for (;;) {

		std::cout << "Please enter a command: ";
		std::cin >> command;
		if (std::cin.eof()) {

			exit(EXIT_SUCCESS);
		}
		if (command == "ADD") {

			phoneBook.addContact();
		} else if (command == "SEARCH") {

			phoneBook.searchContact();
		} else if (command == "EXIT") {

			exit(EXIT_SUCCESS);
		} else {

			std::cout << "Pas ca mek" << std::endl;
		}
	}
	return (0);
}
