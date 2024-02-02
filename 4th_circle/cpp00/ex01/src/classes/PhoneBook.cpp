/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:46:04 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/02 18:10:46 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook() {}

void	PhoneBook::initPhoneBook(void) {

	this->_nbContacts = -1;
}

void	PhoneBook::addContact(void) {

	Contact		contact;
	std::string	str;

	do {

		std::cout << "First name: ";
		this->_prompt();
	} while (!Contact::checkName(this->_input));
	contact.setFirstName(str);
	do {

		std::cout << "Last name: ";
		this->_prompt();
	} while (!Contact::checkName(str));
	contact.setLastName(str);
	do {

		std::cout << "Nickname: ";
		this->_prompt();
	} while (!Contact::checkPrint(str));
	contact.setNickname(str);
	do {

		std::cout << "Phone number: ";
		this->_prompt();
	} while (!Contact::checkNumber(str));
	contact.setPhoneNumber(str);
	do {

		std::cout << "Darkest secret: ";
		this->_prompt();
	} while (!Contact::checkPrint(str));
	contact.setDarkestSecret(str);
	this->_nbContacts++;
	if (this->_nbContacts == 9) {

		this->_nbContacts = 0;
	}
	this->_contacts[this->_nbContacts] = contact;
}

void	PhoneBook::_prompt(void) {

	std::string	value;

	if (!std::cin) {

		exit(EXIT_SUCCESS);
	}
	std::cin >> value;
	if (std::cin.eof()) {

		exit(EXIT_SUCCESS);
	}
	this->_input = value;
}

void	PhoneBook::searchContact(void) const {

	std::cout << "|----------|-------Contact-------|----------|" << std::endl;
	std::cout << "|Index     |First name|Last name |Nickname  |" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++) {

		std::cout << "|         " << i + 1 << "|";
		this->_contacts[i].printLineContact();
		std::cout << std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}
