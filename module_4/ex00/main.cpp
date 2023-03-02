/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:40:51 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/02 14:24:59 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
# include "colors.hpp"

int	main(void)
{
	{
		std::cout << RED_B << "FIRST TEST" << RESET << std::endl;
		Animal	animal;
		Animal	*cat = new Cat();
		Animal	*dog = new Dog();
		Animal	dog2;
		Dog		dog3;
		Dog		dog4;

		// dog3 = dog2; // cannot convert Dog = Animal;
		dog2 = dog3; // can with Animal = Dog
		dog4 = dog3;
		
		std::cout << RESET << std::endl;
		std::cout << "type animal = " << animal.getType() << std::endl;
		std::cout << "type cat = " << cat->getType() << std::endl;
		std::cout << "type dog = " << dog->getType() << std::endl;
		std::cout << "type dog3 = " << dog3.getType() << std::endl;
		std::cout << "type dog2 = " << dog2.getType() << std::endl;
		
		std::cout << std::endl;
		animal.makeSound();
		cat->makeSound();
		dog->makeSound();
		dog2.makeSound();
		dog3.makeSound();
		std::cout << std::endl;
		
		delete cat;
		delete dog;

		std::cout << std::endl;
	}
	
	{
		std::cout << std::endl;
		std::cout << RED_B << "SECOND TEST" << RESET << std::endl;
		WrongAnimal	animal;
		WrongAnimal	*cat = new WrongCat();
		WrongCat	cat2;
		
		std::cout << RESET << std::endl;
		std::cout << "type animal = " << animal.getType() << std::endl;
		std::cout << "type cat = " << cat->getType() << std::endl;
		std::cout << "type cat2 = " << cat2.getType() << std::endl;
		
		std::cout << std::endl;
		animal.makeSound();
		cat->makeSound();
		cat2.makeSound();
		std::cout << std::endl;
		
		delete cat;

		std::cout << std::endl;
	}
	
	{
		std::cout << std::endl;
		std::cout << RED_B << "MAIN TEST" << RESET << std::endl;
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		
		delete meta;
		delete j;
		delete i;
	}
	
	{
		std::cout << std::endl;
		std::cout << RED_B << "MAIN WRONG TEST" << RESET << std::endl;
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		WrongCat	trueCat;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will NOT output the cat sound!
		trueCat.makeSound(); // will output the cat sound
		meta->makeSound();
		
		delete meta;
		delete i;
	}
	return 0;
}
