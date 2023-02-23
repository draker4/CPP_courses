/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:07:20 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/23 16:57:20 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "colors.hpp"

int	main(void)
{
	{
		std::cout << WHITE_B << BLACK_F << "ClapTrap class tests:" << RESET << std::endl;
		
		ClapTrap	paul("Paul");
		ClapTrap	quentin("Quentin");

		std::cout << RED_F << quentin << std::endl;
		quentin.attack("cat");
		quentin.beRepaired(4);
		paul.takeDamage(5);
		paul.beRepaired(6);
	}
	{
		std::cout << std::endl;
		std::cout << WHITE_B << BLACK_F << "ScavTrap class tests:" << RESET << std::endl;
		
		ScavTrap	arthur("arthur");
		ScavTrap	arthur_copy(arthur);
		
		arthur.attack("poney");
		arthur_copy.takeDamage(8);
		arthur_copy.beRepaired(4);
		arthur_copy.beRepaired(20);
		arthur.guardGate();
	}
}
