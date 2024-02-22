/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 22:03:45 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/22 08:03:51 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main( void ) {

	ClapTrap	a = ClapTrap( "Gerard" );
	FragTrap	b = FragTrap( "Gonzague" );

	std::cout << std::endl << a << std::endl;
	std::cout << b << std::endl << std::endl;

	a.attack( "Gonzague" );
	b.takeDamage( a.getAttackDamage() );
	b.attack( "a mean wall" );

	std::cout << std::endl << b << std::endl << std::endl;

	b.setEnergyPoints( 2 );

	for ( int i = 0; i < 3; i++ ) {

		b.highFivesGuys();
	}

	b.setEnergyPoints( 42 );

	std::cout << b << std::endl << std::endl;

	b.takeDamage( 3 );

	std::cout << b << std::endl << std::endl;

	b.beRepaired( 10 );
	b.setEnergyPoints( 2 );
	b.takeDamage( BEAUCOUP );

	std::cout << b << std::endl << std::endl;

	b.attack( "Gerard" );
	b.beRepaired( 10 );
	b.takeDamage( MOINS );
	b.highFivesGuys();

	return 0;
}
