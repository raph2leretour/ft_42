/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:04:01 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/04 16:39:53 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {

private:
	std::string	_input;
	int			_nbContacts;

	void		_prompt(void);

	Contact		_contacts[8];

public:
	PhoneBook(void);
	~PhoneBook();

	void		initPhoneBook(void);
	void		phoneBookExecute(void);
	void		addContact(void);
	void		searchContact(void);
};

#endif
