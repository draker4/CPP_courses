/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:18:41 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/07 14:22:11 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zombies = zombieHorde(15, "Georges");
	Zombie	*zombies2 = zombieHorde(4, "Charles");

	for (int i = 0; i < 15; i++)
		zombies[i].announce();
	for (int i = 0; i < 4; i++)
		zombies2[i].announce();
	delete [] zombies;
	delete [] zombies2;
	return (0);
}
