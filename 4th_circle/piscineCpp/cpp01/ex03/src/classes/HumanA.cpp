/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:52:25 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/10 19:34:12 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon ) : _name( name ), _weapon( &weapon ) {}

HumanA::~HumanA( void ) {}

void	HumanA::attack( void ) const {

	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
