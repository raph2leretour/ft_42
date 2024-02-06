/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:46:19 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/06 17:59:34 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void ) {}

Contact::~Contact( void ) {}

std::string	Contact::getFirstName( void ) const {

	return this->_firstName;
}

void	Contact::setFirstName( std::string firstName ) {

	this->_firstName = firstName;
}

std::string	Contact::getLastName( void ) const {

	return this->_lastName;
}

void	Contact::setLastName( std::string lastName ) {

	this->_lastName = lastName;
}

std::string	Contact::getNickname( void ) const {

	return this->_nickname;
}

void	Contact::setNickname( std::string nickname ) {

	this->_nickname = nickname;
}

std::string	Contact::getPhoneNumber( void ) const {

	return this->_phoneNumber;
}

void	Contact::setPhoneNumber( std::string phoneNumber ) {

	this->_phoneNumber = phoneNumber;
}

std::string	Contact::getDarkestSecret( void ) const {

	return this->_darkestSecret;
}

void	Contact::setDarkestSecret( std::string darkestSecret ) {

	this->_darkestSecret = darkestSecret;
}

void	Contact::printName( std::string name ) const {

	if ( name.length() < 10 ) {

		for ( int i = name.length(); i < 10; i++ ) {

			std::cout << " ";
		}
		std::cout << name;
	} else if ( name.length() > 10 ) {

		for ( int i = 0; i < 9; i++ ) {

			std::cout << name[ i ];
		}
		std::cout << ".";
	} else {

		std::cout << name;
	}
}

void	Contact::printLineContact( void ) const {

	this->printName( this->_firstName );
	std::cout << "|";
	this->printName( this->_lastName );
	std::cout << "|";
	this->printName( this->_nickname );
	std::cout << "|";
}

void	Contact::printRawContact( void ) const {

	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}

bool	Contact::checkName( std::string name ) {

	if ( name.length() == 0 ) {

		return false;
	}
	for ( std::string::iterator it = name.begin(); it != name.end(); it++ ) {

		char	c = *it;
		if ( !isalpha( c ) && c != '-' ) {

			return false;
		}
	}

	return true;
}

bool	Contact::checkPrint( std::string str ) {

	if ( str.length() == 0 ) {

		return false;
	}
	for ( std::string::iterator it = str.begin(); it != str.end(); it++ ) {

		char	c = *it;
		if ( !isprint( c ) ) {

			return false;
		}
	}

	return true;
}

bool	Contact::checkNumber( std::string number ) {

	if ( number.length() == 0 ) {

		return false;
	}
	for ( std::string::iterator it = number.begin(); it != number.end(); it++ ) {

		char	c = *it;
		if  ( !isdigit( c ) ) {

			return false;
		}
	}

	return true;
}
