/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:51:54 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/10 20:31:03 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name( name ) {

	this->_weapon = NULL;
}

HumanB::~HumanB( void ) {}

void	HumanB::setWeapon( Weapon& weapon ) {

	this->_weapon = &weapon;
}

void	HumanB::attack( void ) const {

	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
