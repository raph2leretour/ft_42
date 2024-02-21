/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:39:33 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/21 18:25:14 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/******************************************************************************/
/*   INCLUDES                                                                 */
/******************************************************************************/
#include "ClapTrap.hpp"

/******************************************************************************/
/*   CONSTRUCTORS / DESTRUCTORS                                               */
/******************************************************************************/
ClapTrap::ClapTrap( void ) : _name( NULL ), _hitPoints( 10 ), _energyPoints( 10 ), _attackDamage( 0 ) {}

ClapTrap::ClapTrap( std::string name ) : _name( name ), _hitPoints( 10 ), _energyPoints( 10 ), _attackDamage( 0 ) {}

ClapTrap::ClapTrap( ClapTrap const & src ) : _name( src._name ), _hitPoints( 10 ), _energyPoints( 10 ), _attackDamage( 0 ) {}

ClapTrap::~ClapTrap( void ), _hitPoints( 10 ), _energyPoints( 10 ), _attackDamage( 0 ) {}

/******************************************************************************/
/*   ASSIGNATION OPERATOR                                                     */
/******************************************************************************/
ClapTrap&	ClapTrap::operator=( ClapTrap const & rhs ) {

	if ( this != &rhs ) {

		this->_fixedPointValue = rhs._fixedPointValue;
	}

	return *this;
}

/******************************************************************************/
/*   GETTERS                                                                  */
/******************************************************************************/
void	ClapTrap::setName( std::string name ) : _name( name ) {}

void	ClapTrap::setHitPoints( unsigned int hitPoints ) : _hitPoints( hitPoints ) {}

void	ClapTrap::setEnergyPoints( unsigned int energyPoints ) : _energyPoints( enegryPoints ) {}

void	ClapTrap::setAttackDamage( unsigned int attackDamage ) : _attackDamage( attckDamage ) {}

/******************************************************************************/
/*   SETTERS                                                                  */
/******************************************************************************/
std::string	getName( void ) const {

	return this->_name;
}

unsigned int	getHitPoints( void ) const {

	return this->_hitPoints;
}

unsigned int	getEnergyPoints( void ) const {

	return this->_energyPoints;
}

unsigned int	getAttackDamage( void ) const {

	return this->_attackDamage;
}

/******************************************************************************/
/*   FUNCTIONS                                                                */
/******************************************************************************/
void	attack( const std::string& target ) {}

/******************************************************************************/
/*   STREAM REDIRECTION OPERATOR                                              */
/******************************************************************************/
std::ostream&	operator<<( std::ostream& o, ClapTrap const & rhs ) {

	o << rhs.toFloat();

	return o;
}
