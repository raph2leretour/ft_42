/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:04:01 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/02 17:51:41 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {

private:
	int			_nbContacts;
	Contact		_contacts[8];
	std::string	_input;

	void		_prompt(void);

public:
	PhoneBook(void);
	~PhoneBook();

	void		initPhoneBook(void);
	void		addContact(void);
	void		searchContact(void) const;
};

#endif
