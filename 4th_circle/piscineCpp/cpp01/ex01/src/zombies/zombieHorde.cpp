/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:12:23 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/09 19:06:34 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name ) {

	Zombie*	zombies = new Zombie[N];

	for (int i = 0; i < N; i++) {

		zombies[i].setName( name );
	}

	return zombies;
}
