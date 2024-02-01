/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:46:19 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/01 15:42:06 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Contact.class.hpp"

Contact::Contact(void) {}

Contact::~Contact() {}

std::string	Contact::getFirstName(void) const {

	return (this->_firstName);
}

void	Contact::setFirstName(std::string firstName) {

	this->_firstName = firstName;
}

std::string	Contact::getLastName(void) const {

	return (this->_lastName);
}

void	Contact::setLastName(std::string lastName) {

	this->_lastName = lastName;
}

std::string	Contact::getNickname(void) const {

	return (this->_nickname);
}

void	Contact::setNickname(std::string nickname) {

	this->_nickname = nickname;
}

std::string	Contact::getPhoneNumber(void) const {

	return (this->_phoneNumber);
}

void	Contact::setPhoneNumber(std::string phoneNumber) {

	this->_phoneNumber = phoneNumber;
}

std::string	Contact::getDarkestSecret(void) const {

	return (this->_darkestSecret);
}

void	Contact::setDarkestSecret(std::string darkestSecret) {

	this->_darkestSecret = darkestSecret;
}

void	Contact::printContact(void) const {

	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}

bool	Contact::checkName(std::string name) {

	for (std::string::iterator it = name.begin(); it != name.end(); it++) {

		char c = *it;
		if (!isalpha(c) || c == '-') {

			return (false);
		}
	}
	return (true);
}

bool	Contact::checkPrint(std::string str) {

	for (std::string::iterator it = str.begin(); it != str.end(); it++) {

		char c = *it;
		if (!isprint(c)) {

			return (false);
		}
	}
	return (true);
}

bool	Contact::checkNumber(std::string number) {

	for (std::string::itarator it = number.begin(); it != number.end(); it++) {

		char c = *it;
		if (!isdigit(c)) {

			return (false);
		}
	}
	return (true);
}
