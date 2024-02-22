/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:09:28 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/22 03:44:02 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
# include "ClapTrap.hpp"

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class ScavTrap : public ClapTrap {

public:
	ScavTrap( void );
	ScavTrap( std::string name );
	ScavTrap( ScavTrap const & src );
	virtual ~ScavTrap( void );

	ScavTrap&	operator=( ScavTrap const & rhs );

	void		attack( const std::string& target );
	void		guardGate( void );

};
