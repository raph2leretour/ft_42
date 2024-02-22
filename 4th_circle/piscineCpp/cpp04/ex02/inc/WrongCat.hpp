/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:17:48 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/22 11:30:12 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "WrongAnimal.hpp"

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class WrongCat : public WrongAnimal {

private:
	std::string	_type;

public:
	WrongCat( void );
	WrongCat( WrongCat const & src );
	virtual ~WrongCat( void );

	WrongCat&	operator=( WrongCat const & rhs );

	std::string	getType( void ) const;

	void		makeSound( void ) const;
};
