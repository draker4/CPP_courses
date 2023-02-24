/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:40:51 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/24 15:58:39 by bperriol         ###   ########lyon.fr   */
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
		int		i;
		AAnimal	*animals[10];
		
		for (i = 0; i < 5; i++)
			animals[i] = new Dog();
		for (i = 5; i < 10; i++)
			animals[i] = new Cat();
			
		std::cout << std::endl << RESET << "before delete" << std::endl;

		for(i = 0; i < 10; i++)
			delete (animals[i]);
	}
	{
		std::cout << "\n\n";
		std::cout << RED_B << "MAIN TEST" << RESET << std::endl;
		
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		j->makeSound();
		i->makeSound();
		delete j;//should not create a leak
		delete i;

	}
	{
		// should not work with abstract class
		// std::cout << "\n\n";
		// std::cout << RED_B << "MAIN TEST" << RESET << std::endl;
		
		// AAnimal	abstract_animal;
	}
	return 0;
}
