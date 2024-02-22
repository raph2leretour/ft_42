/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 04:15:05 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/22 06:52:01 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "FragTrap.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
FragTrap::FragTrap( void ) {

	_name = "Gedeon";
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap Default Constructor called;
	std::cout << "." << std::endl;
}

FragTrap::FragTrap( std::string name ) {

	_name = name;
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "FragTrap String Constructor called from " << _name;
	std::cout << "." << std::endl;
}

FragTrap::FragTrap( FragTrap const & src ) {

	_name = src._name;
	_hitPoints = src._hitPoints;
	_energyPoints = src._energyPoints;
	_attackDamage = src._attackDamage;

	std::cout << "FragTrap Copy Constructor called from " << _name;
	std::cout << "." << std::endl;
}

FragTrap::~FragTrap( void ) {

	std::cout << "FragTrap Destructor called from " << _name;
	std::cout << "." << std::endl;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	FragTrap::highFivesGuys( void ) {

	if ( _hitPoints == 0 ) {

		std::cout << "FragTrap " << _name;
		std::cout << " can't high five, " << _name;
		std::cout << " is already dead (#ripbozo 😹👎👎)" << std::endl;
	} else if ( _energyPoints == 0 ) {

		std::cout << "FragTrap " << _name;
		std::cout << " can't high five, " << _name;
		std::cout << " has no remaining energy points!" << std::endl;
	} else {

		--_energyPoints;

		std::cout << "FragTrap " << _name;
		std::cout << " high five!" << std::endl;
	}
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
FragTrap&	FragTrap::operator=( FragTrap const & rhs ) {

	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;

	return *this;
}
