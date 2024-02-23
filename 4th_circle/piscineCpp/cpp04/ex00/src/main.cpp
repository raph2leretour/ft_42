/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:15:27 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/23 13:32:05 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main( void ) {

	std::cout << std::endl << "---------------------Animal tets---------------------" << std::endl;

	std::cout << std::endl << "Create some Animals." << std::endl;
	const Animal*	 	meta = new Animal();
	const Animal* 		dog = new Dog();
	const Animal* 		cat = new Cat();

	std::cout << std::endl << "Do the Roar!" << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl << "Destroy some Animals." << std::endl;
	delete meta;
	delete dog;
	delete cat;

	std::cout << std::endl << "------------------Wrong Animal tets------------------";
	std::cout << std::endl << std::endl;

	std::cout << std::endl << "Create some Animals." << std::endl;
	const WrongAnimal*	wrongMeta = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();

	std::cout << std::endl << "Do the Roar!" << std::endl;
	wrongMeta->makeSound();
	wrongCat->makeSound();

	std::cout << std::endl << "Destroy some Animals." << std::endl;
	delete wrongMeta;
	delete wrongCat;

	return 0;
}
