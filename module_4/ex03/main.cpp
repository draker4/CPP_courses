/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:18:15 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/01 11:35:21 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main(void)
{
	{
		std::cout << RED_B << "MAIN TEST" << RESET << std::endl;

		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
	}
	
	{
		std::cout << "\n\n";
		std::cout << RED_B << "My test 1" << RESET << std::endl;
		
		AMateria	*mat1 = new Ice();
		AMateria	*mat2 = new Cure();
		ICharacter	*Bapt = new Character("Bapt");
		ICharacter	*Luis = new Character("Luis");
		
		std::cout << std::endl;
		Luis->equip(mat1);
		Bapt->equip(mat1);
		Bapt->equip(mat2);
		std::cout << std::endl;

		delete Bapt;
		delete Luis;
	}
	
	{
		std::cout << "\n\n";
		std::cout << RED_B << "My test 2" << RESET << std::endl;
		
		AMateria	*mat1 = new Ice();
		AMateria	*mat2 = new Cure();
		Character	Charles("Charles");
		Character	Henry("Henry");
		
		std::cout << std::endl;
		Charles.equip(mat1);
		Charles.equip(mat1);
		Henry.equip(mat2);
		Henry.equip(mat2);
		Henry = Charles;
		Henry.use(1, Charles);
		std::cout << std::endl;
	}
	
	{
		std::cout << "\n\n";
		std::cout << RED_B << "My test 3" << RESET << std::endl;
		
		AMateria	*mat1 = new Ice();
		AMateria	*mat2 = new Cure();
		Character	Charles("Charles");
		
		std::cout << std::endl;
		Charles.equip(mat1);
		Charles.equip(mat2);
		Charles.equip(mat2);
		Charles.unequip(1);
		Charles.find(3);
		std::cout << std::endl;
	}
	
	std::cout << RESET;
	return 0;
}
