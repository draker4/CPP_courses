/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:27:34 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/02 16:51:34 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.hpp"
#include "Conversion.hpp"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
	{
		std::cerr << RED_B << "Please enter one argument and one only!" << RESET << std::endl;
		return 1;
	}
	try {
		Conversion	test(argv[1]);
		Conversion	test2(test);
		
		std::cout << test2;
	}
	catch (std::exception &e)
	{
		std::cout << "error with conversion because : " << e.what() << std::endl;
	}
	
	return 0;
}
