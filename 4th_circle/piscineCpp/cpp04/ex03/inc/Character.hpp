/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 18:13:47 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/26 18:10:31 by rtissera         ###   ########.fr       */
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

private:
	std::string	_name;
	AMateria*	_m[ 4 ];

public:
	Character( void );
	Character( std::string const & name );
	Character( Character const & src );
	virtual ~Character( void );

	Character&	operator=( Character const & rhs );

	std::string	getName( void ) const;

	void		equip( AMateria* m );
	void		unequip( int idx );
	void		use( int idx, ICharachter& target );

};
