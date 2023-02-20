/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:26:43 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/20 12:10:58 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie("Paul");
	Zombie	*zombie2 = newZombie("Arthur");

	std::cout << std::endl;
	std::cout << "Zombie Paul is created on the stack" << std::endl;
	std::cout << "Zombie Arthur is created on the heap" << std::endl;

	std::cout << std::endl;
	zombie2->announce();
	zombie.announce();

	std::cout << std::endl;
	std::cout << "Random chump creates a zombie named Etoile on the stack in the function, so i can not access it here" << std::endl;
	randomChump("Etoile");
	
	std::cout << std::endl;
	std::cout << "Zombie Arthur on the heap has to be deleted" <<std::endl;
	delete zombie2;
	
	std::cout << std::endl;
	return (0);
}
