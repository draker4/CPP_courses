/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:18:41 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/20 12:16:32 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies1 = zombieHorde(15, "Georges");
	Zombie	*zombies2 = zombieHorde(4, "Charles");

	for (int i = 0; i < 15; i++)
		zombies1[i].announce();
	std::cout << std::endl;
	for (int i = 0; i < 4; i++)
		zombies2[i].announce();
	delete [] zombies1;
	delete [] zombies2;
	return (0);
}
