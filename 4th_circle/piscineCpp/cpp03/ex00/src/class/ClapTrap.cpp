/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:33 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/21 22:37:15 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "ClapTrap.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
ClapTrap::ClapTrap( void ) : _name( NULL ), _hitPoints( 10 ), _energyPoints( 10 ), _attackDamage( 0 ) {

	std::cout << "Default Constructor called from " << _name << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : _name( name ), _hitPoints( 10 ), _energyPoints( 10 ), _attackDamage( 0 ) {

	std::cout << "String Constructor called from " << _name << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & src ) : _name( src._name ), _hitPoints( 10 ), _energyPoints( 10 ), _attackDamage( 0 ) {

	std::cout << "Copy Constructor called from " << _name << std::endl;
}

ClapTrap::~ClapTrap( void ) {

	std::cout << "Destructor called from " << _name << std::endl;
}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
ClapTrap&	ClapTrap::operator=( ClapTrap const & rhs ) {

	_name = rhs._name;
	_hitPoints = rhs._hitPoints;
	_energyPoints = rhs._energyPoints;
	_attackDamage = rhs._attackDamage;

	return *this;
}

/******************************************************************************/
/*   GETTERS                                                                  */
/******************************************************************************/
void	ClapTrap::setName( std::string name ) {

	_name = name;
}

void	ClapTrap::setHitPoints( unsigned int hitPoints ) {

	_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints( unsigned int energyPoints ) {

	_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDamage( unsigned int attackDamage ) {

	_attackDamage = attackDamage;
}

/******************************************************************************/
/*   SETTERS                                                                  */
/******************************************************************************/
std::string	ClapTrap::getName( void ) const {

	return _name;
}

unsigned int	ClapTrap::getHitPoints( void ) const {

	return _hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints( void ) const {

	return _energyPoints;
}

unsigned int	ClapTrap::getAttackDamage( void ) const {

	return _attackDamage;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	ClapTrap::attack( const std::string& target ) {

	if ( _energyPoints == 0) {

		std::cout << "ClapTrap " << _name;
		std::cout << " has no remaining energy points!" << std::endl;
	} else if (_hitPoints == 0) {
		
		std::cout << "ClapTrap " << _name;
		std::cout << " is dead (#ripbozo :joy_cat: :thumbsdown: :thumbsdown:)" << std::endl;
	} else {

		std::cout << "ClapTrap " << _name;
		std::cout << " attacks " << target;
		std::cout << ", causing " << _attackDamage;
		std::cout << " points of damage!" << std::endl;

		--_energyPoints;
	}
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	if ( _hitPoints == 0 ) {

		std::cout << "ClapTrap " << _name;
		std::cout << " is already dead (#ripbozo :joy_cat: :thumbsdown: :thumbsdown:)" << std::endl;
	} else {

		std::cout << "ClapTrap " << _name;
		std::cout << " takes " << amount;
		std::cout << " damage" << std::endl;

		if ( amount > _hitPoints ) {

			_hitPoints = 0;
		} else {

			_hitPoints -= amount;
		}
	}
}

void	ClapTrap::beRepaired( unsigned int amount ) {

	if ( _energyPoints == 0 || _hitPoints == 0 ) {

		std::cout << "ClapTrap " << _name << " can't be repaired" << std::endl;
	} else {

		_hitPoints += amount;

		if ( _hitPoints > 10 ) {

			_hitPoints = 10;
		}

		--_energyPoints;

		std::cout << "ClapTrap " << _name << " repaired" << std::endl;
	}
}

/******************************************************************************/
/*   REDIRECTION OPERATOR                                                     */
/******************************************************************************/
/*std::ostream&	operator<<( std::ostream& o, ClapTrap const & rhs ) {

	o << rhs._name;

	return o;
}*/
