/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:15:27 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 16:32:34 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main( void ) {

	int num = 10;
	const AAnimal* j = new Dog();
	const AAnimal* c = new Cat();
	AAnimal* b[10];

	int i =0;
	while (i < num / 2)
	{
		b[i] = new Dog();
		i++;
	}
	while (i < num)
	{
		b[i] = new Cat();
		i++;
	}

	delete j;
	delete c;

	for ( int i = 0; i < num; i++ ) {
		b[i]->printIdeas();
		b[i]->makeSound();
		delete b[i];
	}

	return 0;
}
