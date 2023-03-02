/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:40:51 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/02 14:22:34 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
# include "colors.hpp"

int	main(void)
{
	{
		std::cout << RED_B << "Copy dog TEST" << RESET << std::endl;
		
		Dog	basic;
		{
			Dog	tmp = basic;
		}
	}
	{
		std::cout << RED_B << "Copy cat TEST" << RESET << std::endl;
		
		Cat	basic;
		{
			Cat	tmp = basic;
		}
	}
	{
		std::cout << RED_B << "FIRST TEST" << RESET << std::endl;
		int		i;
		Animal	*animals[100];
		
		for (i = 0; i < 50; i++)
			animals[i] = new Dog();
		for (i = 50; i < 100; i++)
			animals[i] = new Cat();
			
		std::cout << std::endl << RESET << "before delete" << std::endl;

		for(i = 0; i < 100; i++)
			delete (animals[i]);
	}
	{
		std::cout << "\n\n";
		std::cout << RED_B << "MAIN TEST" << RESET << std::endl;
		
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	return 0;
}
