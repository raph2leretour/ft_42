/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:04:01 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/01 19:07:09 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {

private:
	Contact		_contacts[8];
	int			_nbContacts;
	std::string	_input;

	void		_prompt(void);

public:
	PhoneBook(void);
	~PhoneBook();

	void		addContact(void);
	void		searchContact(void) const;
};

#endif
