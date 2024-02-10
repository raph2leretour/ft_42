/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:53:42 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/10 19:56:10 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type( type ) {}

Weapon::~Weapon( void ) {}

std::string	Weapon::getType( void ) const {

	return this->_type;
}

void	Weapon::setType( std::string type ) {

	this->_type = type;
}
