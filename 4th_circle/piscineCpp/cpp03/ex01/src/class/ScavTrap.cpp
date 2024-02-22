/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 01:21:58 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/22 06:52:40 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "ScavTrap.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
ScavTrap::ScavTrap( void ) {

	_name = "Gedeon";
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap Default Constructor called";
	std::cout << "." << std::endl;
}

ScavTrap::ScavTrap( std::string name ) {

	_name = name;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;

	std::cout << "ScavTrap String Constructor called from " << _name;
	std::cout << "." << std::endl;
}

ScavTrap::ScavTrap( ScavTrap const & src ) {

	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;

	std::cout << "ScavTrap Copy Constructor called from " << _name;
	std::cout << "." << std::endl;
}

ScavTrap::~ScavTrap( void ) {

	std::cout << "ScavTrap Destructor called from " << _name;
	std::cout << "." << std::endl;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
ScavTrap&	ScavTrap::operator=( ScavTrap const & rhs ) {

	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;

	return *this;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	ScavTrap::attack( const std::string& target ) {

	if (_hitPoints == 0) {
		
		std::cout << "ScavTrap " << _name;
		std::cout << " can't attack, " << _name;
		std::cout << " is dead (#ripbozo 😹👎👎)" << std::endl;
	} else if ( _energyPoints == 0) {

		std::cout << "ScavTrap " << _name;
		std::cout << " can't attack, " << _name;
		std::cout << " has no remaining energy points!" << std::endl;
	} else {

		std::cout << "ScavTrap " << _name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << _attackDamage;
		std::cout << " points of damage!" << std::endl;

		--_energyPoints;
	}
}

void	ScavTrap::guardGate( void ) {

	if ( _hitPoints == 0 ) {

		std::cout << "ScavTrap " << _name;
		std::cout << " can't take damage, " << _name;
		std::cout << " is already dead (#ripbozo 😹👎👎)" << std::endl;
	} else if ( _energyPoints == 0 ) {

		std::cout << "ScavTrap " << _name;
		std::cout << " can't keep the Gate, " << _name;
		std::cout << " has no remaining energy points!" << std::endl;
	} else {

		--_energyPoints;

		std::cout << "ScavTrap " << _name;
		std::cout << " is now in Gate keeper mode." << std::endl;
	}
}
