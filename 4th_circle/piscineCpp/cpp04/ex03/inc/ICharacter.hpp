/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:32:53 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/27 16:40:27 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include <iostream>
#include "AMateria.hpp"

class AMateria;

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class ICharacter {

public:
	virtual ~ICharacter( void ) {}

	virtual std::string const &	getName( void ) const = 0;

	virtual void			equip( AMateria* m ) = 0;
	virtual void			unequip( int idx ) = 0;
	virtual void			use( int idx, ICharacter& target ) = 0;
};
