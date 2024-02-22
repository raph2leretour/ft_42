/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:03:45 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/22 03:47:59 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void ) {

	ClapTrap	a = ClapTrap( "Gerard" );
	ScavTrap	b = ScavTrap( "Geraldine" );

	std::cout << std::endl << a << std::endl;
	std::cout << b << std::endl << std::endl;

	for ( int i = 0; i < 4; i++ ) {

		a.attack( "Geraldine" );
		b.takeDamage( a.getAttackDamage() );
		b.attack( "Gerard" );
		a.takeDamage( b.getAttackDamage() );

		std::cout << std::endl << a << std::endl;
		std::cout << b << std::endl << std::endl;
	}

	for ( int i = 0; i < 2; i++ ) {

		b.beRepaired( 1 );

		std::cout << b << std::endl << std::endl;
	}

	b.setEnergyPoints( 2 );

	for ( int i = 0; i < 3; i++ ) {

		b.guardGate();
	}

	b.setEnergyPoints( 42 );

	std::cout << b << std::endl << std::endl;

	b.takeDamage( 3 );

	std::cout << b << std::endl << std::endl;

	a.setHitPoints( 9 );
	a.beRepaired( 2 );

	std::cout << a << std::endl << std::endl;

	b.attack( "Gerard" );
	b.beRepaired( 10 );
	b.setEnergyPoints( 2 );
	b.takeDamage( BEAUCOUP );

	std::cout << b << std::endl << std::endl;

	b.attack( "Gerard" );
	b.beRepaired( 10 );
	b.takeDamage( MOINS );

	return 0;
}
