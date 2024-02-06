/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:34:59 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/06 17:58:02 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main( void ) {

	PhoneBook	phoneBook;

	phoneBook.initPhoneBook();
	phoneBook.phoneBookExecute();

	return 0;
}
