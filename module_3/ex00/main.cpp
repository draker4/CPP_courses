/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:07:20 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/23 16:27:02 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.hpp"

int	main(void)
{
	ClapTrap	paul("Paul");
	ClapTrap	quentin("Quentin");

	std::cout << RED_F << quentin << std::endl;
	quentin.attack("cat");
	quentin.beRepaired(4);
	paul.takeDamage(5);
}
