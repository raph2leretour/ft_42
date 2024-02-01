/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:46:04 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/01 19:06:55 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook() {}

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

void	PhoneBook::searchContact(void) const {}
