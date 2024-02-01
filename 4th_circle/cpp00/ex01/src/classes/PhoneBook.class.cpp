/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:46:04 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/01 16:05:31 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(void) {

	Contact		contact;
	std::string	str;

	std::cout << "First name: ";
	while (!Contact::checkName(str)) {

		std::cout << "First name: ";
		std::cin >> str;
		if (std::cin.eof()) {

			exit(EXIT_SUCCESS);
		}
	}
	contact.setFirstName(str);
	std::cout << "Last name: ";
	while (!Contact::checkName(str)) {

		std::cout << "Last name: ";
		std::cin >> str;
		if (std::cin.eof()) {

			exit(EXIT_SUCCESS);
		}
	}
	contact.setLastName(str);
	std::cout << "Nickname: ";
	while (!Contact::checkPrint(str)) {

		std::cout << "Nickname: ";
		std::cin >> str;
		if (std::cin.eof()) {

			exit(EXIT_SUCCESS);
		}
	}
	contact.setNickname(str);
	std::cout << "Phone number: ";
	while (!Contact::checkNumber(str)) {

		std::cout << "Phone Number: ";
		std::cin >> str;
		if (std::cin.eof()) {

			exit(EXIT_SUCCESS);
		}
	}
	contact.setPhoneNumber(str);
	std::cout << "Darkest secret: ";
	while (!Contact::checkPrint(str)) {

		std::cout << "Darkest secret: ";
		std::cin >> str;
		if (std::cin.eof()) {

			exit(EXIT_SUCCESS);
		}
	}
	contact.setDarkestSecret(str);
}

void	PhoneBook::searchContact(void) const {


}
