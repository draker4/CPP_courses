/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:34:50 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/09 13:00:05 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "colors.hpp"

int	main(void)
{
	{
		std::cout << std::endl;
		std::cout << YELLOW_F << "First test" << RESET << std::endl;
		std::cout << std::endl;
		
		Span	test1(4);
		
		try {
			
			for (int i = 0; i < 4; i++)
				test1.addNumber(i);
				
			std::cout << std::endl;
			std::cout << "shortest span = " << test1.shortestSpan() << std::endl;
			std::cout << "longest span = " << test1.longestSpan() << std::endl;
		
		}
		catch (std::exception &e) {
			std::cout << "error because : " << e.what() << std::endl;
		}
		std::cout << test1 << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << YELLOW_F << "Second test" << RESET << std::endl;
		std::cout << std::endl;
		
		Span	test1(10000);
		
		try {
			
			for (int i = 0; i < 10000; i++)
				test1.addNumber(i);
				
			std::cout << std::endl;
			std::cout << "shortest span = " << test1.shortestSpan() << std::endl;
			std::cout << "longest span = " << test1.longestSpan() << std::endl;
		
		}
		catch (std::exception &e) {
			std::cout << "error because : " << e.what() << std::endl;
		}
	}

	{
		std::cout << std::endl;
		std::cout << YELLOW_F << "Main test" << RESET << std::endl;
		std::cout << std::endl;
		
		Span	test1(5);
		
		try {
			
			test1.addNumber(6);
			test1.addNumber(3);
			test1.addNumber(17);
			test1.addNumber(9);
			test1.addNumber(11);
				
			std::cout << std::endl;
			std::cout << "shortest span = " << test1.shortestSpan() << std::endl;
			std::cout << "longest span = " << test1.longestSpan() << std::endl;

		}
		catch (std::exception &e) {
			std::cout << "error because : " << e.what() << std::endl;
		}
		std::cout << test1 << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << YELLOW_F << "AddNumber range test" << RESET << std::endl;
		std::cout << std::endl;
		
		Span				test1(10001);
		std::vector<int>	vec(10000, 1);
		
		vec.push_back(200);
		
		try {
			
			test1.addNumber(vec.begin(), vec.end());
				
			std::cout << std::endl;
			std::cout << "shortest span = " << test1.shortestSpan() << std::endl;
			std::cout << "longest span = " << test1.longestSpan() << std::endl;

		}
		catch (std::exception &e) {
			std::cout << "error because : " << e.what() << std::endl;
		}
		// std::cout << test1 << std::endl;
	}
}
