/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:30:38 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/22 03:43:55 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
# include <iostream>

/******************************************************************************/
/*   DEFINES                                                                  */
/******************************************************************************/
# ifndef BEAUCOUP
#  define BEAUCOUP 93274
# endif

# ifndef MOINS
#  define MOINS 4
# endif

/******************************************************************************/
/*   CLASSES                                                                  */
/******************************************************************************/
class ClapTrap {

protected:
	std::string	_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

public:
	ClapTrap( void );
	ClapTrap( std::string name );
	ClapTrap( ClapTrap const & src );
	virtual ~ClapTrap( void );

	ClapTrap&	operator=( ClapTrap const & rhs );

	void		setName( std::string name );
	void		setHitPoints( unsigned int hitPoints );
	void		setEnergyPoints( unsigned int energyPoints );
	void		setAttackDamage( unsigned int attackDamage );

	std::string	getName( void ) const;
	unsigned int	getHitPoints( void ) const;
	unsigned int	getEnergyPoints( void ) const;
	unsigned int	getAttackDamage( void ) const;

	void		attack( const std::string& target );
	void		takeDamage( unsigned int amount );
	void		beRepaired( unsigned int amount );

};

std::ostream&		operator<<( std::ostream& o, ClapTrap const & rhs );
