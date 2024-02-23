/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:13:47 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 18:16:43 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "ICharacter.hpp"

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class Character {

public:
	Character( void );
	Character( std::string const & type );
	Character( Character const & src );
	_Character( void ) {}

	Character&		operator=( Character const & rhs );

	std::string const &	getName( void );
	void			equip( Character* m );
	void			unequip( int idx );
	void			use( int idx, ICharachter& target );
};
