/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:34:50 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/09 12:09:24 by bperriol         ###   ########lyon.fr   */
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
		test1.addNumber(3);
		test1.addNumber(4);
		test1.addNumber(5);
		test1.addNumber(6);
		test1.addNumber(7);
		}
		catch (std::exception &e) {
			std::cout << "error because : " << e.what() << std::endl;
		}
		std::cout << test1 << std::endl;
	}
}
