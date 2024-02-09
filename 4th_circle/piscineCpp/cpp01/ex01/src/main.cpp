/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:18:59 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/09 19:12:36 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void ) {

	int	n = 42;

	if (n < 0) {

		return -1;
	}
	Zombie*	zombies = zombieHorde( n, "Claude" );

	for (int i = 0; i < n; i++) {

		zombies[i].announce();
	}

	delete [] zombies;

	return 0;
}
