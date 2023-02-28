/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:07:20 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 16:53:00 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include "colors.hpp"

int	main(void)
{
	{
		std::cout << WHITE_B << BLACK_F << "ClapTrap class tests:" << RESET << std::endl;
		
		ClapTrap	paul("Paul");
		ClapTrap	quentin("Quentin");

		std::cout << RESET << quentin << std::endl;
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
	{
		std::cout << std::endl;
		std::cout << WHITE_B << BLACK_F << "FragTrap class tests:" << RESET << std::endl;
		
		FragTrap	charles("charles");
		FragTrap	charles_copy(charles);
		
		charles.attack("poney");
		charles_copy.takeDamage(8);
		charles_copy.beRepaired(4);
		charles_copy.beRepaired(20);
		charles_copy.attack("Roger");
		charles.highFivesGuys();
		std::cout << RED_F << "Charles copy used " << 100 - charles_copy.getEnergyPoints() << " energy points" << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << WHITE_B << BLACK_F << "DiamondTrap class tests:" << RESET << std::endl;
		
		DiamondTrap	henry("henry");
		DiamondTrap	henry_copy(henry);

		std::cout << "\n\n" << std::endl;
		
		henry.attack("poney");
		henry_copy.takeDamage(8);
		henry_copy.beRepaired(4);
		henry_copy.beRepaired(20);
		henry_copy.attack("Roger");
		henry.highFivesGuys();
		henry.whoAmI();
		henry_copy.whoAmI();

		std::cout << "\n\n" << std::endl;
		
		std::cout << RED_F << "Henry copy used " << 50 - henry_copy.getEnergyPoints() << " energy points" << std::endl;
	}
}
