/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:04:01 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/01 16:04:42 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H

class PhoneBook {

private:
	Contact		_contacts[8];
	int			_nbContacts;

public:
	PhoneBook(void);
	~PhoneBook();

	void		addContact(void);
	void		searchContact(void) const;

};

#endif
