/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:26:43 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/07 14:18:37 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	zombie("Paul");
	Zombie	*zombie2 = newZombie("Arthur");

	std::cout << "Zombie Paul is created on the stack" << std::endl;
	std::cout << "Zombie Arthur is created on the heap" << std::endl;

	zombie2->announce();
	zombie.announce();

	std::cout << "Random chump create a zombie named Etoile on the stack in the function, so i can not access it here" << std::endl;
	randomChump("Etoile");
	
	std::cout << "Zombie Arthur on the heap has to be deleted" <<std::endl;
	delete zombie2;
	
	return (0);
}
