/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:46:04 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/06 17:57:33 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook( void ) {}

PhoneBook::~PhoneBook( void ) {}

void	PhoneBook::initPhoneBook( void ) {

	this->_nbContacts = -1;
}

void	PhoneBook::phoneBookExecute( void ) {

	std::cout << "Welcome to your PhoneBook!" << std::endl;
	for ( ;; ) {

		std::cout << "Please enter a command: ";
		this->_prompt();
		if ( this->_input == "ADD" ) {

			this->addContact();
		} else if ( this->_input == "SEARCH" ) {

			this->searchContact();
		} else if ( this->_input == "EXIT" ) {

			exit( EXIT_SUCCESS );
		} else {

			std::cout << "Invalid command" << std::endl;
		}
	}
}

void	PhoneBook::addContact( void ) {

	this->_nbContacts++;
	if ( this->_nbContacts == 8 ) {

		this->_nbContacts = 0;
	}
	do {

		std::cout << "First name: ";
		this->_prompt();
	} while ( Contact::checkName( this->_input ) == false );
	this->_contacts[ this->_nbContacts ].setFirstName( this->_input );
	do {

		std::cout << "Last name: ";
		this->_prompt();
	} while ( Contact::checkName( this->_input ) == false );
	this->_contacts[ this->_nbContacts ].setLastName( this->_input );
	do {

		std::cout << "Nickname: ";
		this->_prompt();
	} while ( Contact::checkPrint( this->_input ) == false );
	this->_contacts[ this->_nbContacts ].setNickname( this->_input );
	do {

		std::cout << "Phone number: ";
		this->_prompt();
	} while ( Contact::checkNumber( this->_input ) == false );
	this->_contacts[ this->_nbContacts ].setPhoneNumber( this->_input );
	do {

		std::cout << "Darkest secret: ";
		this->_prompt();
	} while ( Contact::checkPrint( this->_input ) == false );
	this->_contacts[ this->_nbContacts ].setDarkestSecret( this->_input );
}

void	PhoneBook::_prompt( void ) {

	std::string	value;

	if ( !std::cin ) {

		exit( EXIT_SUCCESS );
	}
	std::getline( std::cin, value );
	if ( std::cin.eof() ) {

		exit( EXIT_SUCCESS );
	}
	this->_input = value;
}

void	PhoneBook::searchContact( void ) {

	int	number;

	std::cout << "|----------|--PhoneBook contacts-|----------|" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for ( int i = 0; i < 8; i++ ) {

		std::cout << "|         " << i + 1 << "|";
		this->_contacts[ i ].printLineContact();
		std::cout << std::endl;
	}
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	do {

		std::cout << "Please enter a valid number: ";
		this->_prompt();
		number = atoi( this->_input.c_str() );
	} while ( this->_input.length() != 1 || number < 1 || number > 8 );
	this->_contacts[ number - 1 ].printRawContact();
}
