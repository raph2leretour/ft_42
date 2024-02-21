/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:03:45 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/21 22:36:36 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void ) {

	ClapTrap	a = ClapTrap( "Gerard" );

	std::cout << "Hit points = " << a.getHitPoints() << std::endl;
	std::cout << "Energy points = " << a.getEnergyPoints() << std::endl;

	for ( int i = 0; i < 4; i++ ) {

		a.attack( "nobody" );

		std::cout << "Energy points = " << a.getEnergyPoints() << std::endl;
	}

	for ( int i = 0; i < 4; i++ ) {

		a.beRepaired( 10 );

		std::cout << "Energy points = " << a.getEnergyPoints() << std::endl;
	}

	std::cout << "Hit points = " << a.getHitPoints() << std::endl;

	a.takeDamage( 3 );

	std::cout << "Hit points = " << a.getHitPoints() << std::endl;
	std::cout << "Energy points = " << a.getEnergyPoints() << std::endl;

	a.beRepaired( 2 );

	std::cout << "Hit points = " << a.getHitPoints() << std::endl;
	std::cout << "Energy points = " << a.getEnergyPoints() << std::endl;

	a.beRepaired( 10 );

	std::cout << "Hit points = " << a.getHitPoints() << std::endl;
	std::cout << "Energy points = " << a.getEnergyPoints() << std::endl;

	return 0;
}
