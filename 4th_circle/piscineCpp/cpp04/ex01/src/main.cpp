/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:15:27 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 20:44:41 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main( void ) {

	{
	int num = 10;
	const Animal* j = new Dog();
	const Animal* c = new Cat();
	Animal* b[10];
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
	delete j;//should not create a leak
	delete c;
	i =0;

	while (i < num)
	{
		b[i]->printIdeas();
		b[i]->makeSound();
		delete b[i];
		i++;
	}
	}

	std::cout << "------------------GivenMain----------------------- " << std::endl;

	{
	const Dog d;
	const Dog g(d);

	Animal* j = new Dog();
	Animal* f = new Dog(d);
	const Animal* i = new Cat();

	*f = *j;

	delete f;
	delete j;//should not create a leak
	delete i;
	}

	const Dog plip;
	{
		Dog plop = plip;
	}

	return 0;
}
