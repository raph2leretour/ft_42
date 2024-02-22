/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtissera <rtissera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:15:27 by rtissera          #+#    #+#             */
/*   Updated: 2024/02/22 12:12:33 by rtissera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main( void ) {

	const Animal*	 	meta = new Animal();
	const Animal* 		dog = new Dog();
	const Animal* 		cat = new Cat();
	const WrongAnimal*	wrongMeta = new WrongAnimal();
	const WrongAnimal*	wrongCat = new WrongCat();

	meta->makeSound();
	dog->makeSound();
	cat->makeSound();
	wrongMeta->makeSound();
	wrongCat->makeSound();

	delete meta;
	delete dog;
	delete cat;
	delete wrongMeta;
	delete wrongCat;

	return 0;
}
