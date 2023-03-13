/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:21:04 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/13 13:53:07 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "MutantStack.hpp"

int	main(void)
{
	{
		std::cout << RED_B << "First test" << RESET << std::endl;
		std::cout << std::endl;

		MutantStack<int>	test;
		test.push(3);
		test.push(398);
		
		MutantStack<int>	copy(test);
		std::cout << "Size = " << copy.size() << std::endl;
	}
	
	{
		std::cout << std::endl;
		std::cout << RED_B << "Second test" << RESET << std::endl;
		std::cout << std::endl;

		MutantStack<int>	test;
		
		test.push(45);
		test.push(7473);
		test.push(362);
		test.push(78);
		test.push(890);
		
		MutantStack<int>::iterator	it;
		for (it = test.begin(); it != test.end(); ++it)
			std::cout << MAGENTA_F << "Test = " << *it << RESET << std::endl;
	}
}
