/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:07:41 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/01 15:38:52 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H

class Contact {

private:
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	Contact(void);
	~Contact();

	std::string	getFirstName(void) const;
	void		setFirstName(std::string firstName);
	std::string	getLastName(void) const;
	void		setLastName(std::string lastName);
	std::string	getNickname(void) const;
	void		setNickname(std::string nickname);
	std::string	getPhoneNumber(void) const;
	void		setPhoneNumber(std::string phoneNumber);
	std::string	getDarkestSecret(void) const;
	void		setDarkestSecret(std::string darkestSecret);
	void		printContact(void) const;

	static bool	checkName(std::string name);
	static bool	checkPrint(std::string str);
	static bool	checkNumber(std::string number);

};

#endif
