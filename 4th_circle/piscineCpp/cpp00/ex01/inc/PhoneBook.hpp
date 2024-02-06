/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:04:01 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/06 17:48:15 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <cstdlib>
#include "Contact.hpp"

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class PhoneBook {

private:
	std::string	_input;
	int			_nbContacts;

	void		_prompt( void );

	Contact		_contacts[8];

public:
	PhoneBook( void );
	~PhoneBook( void );

	void		initPhoneBook( void );
	void		phoneBookExecute( void );
	void		addContact( void );
	void		searchContact( void );
};

#endif
