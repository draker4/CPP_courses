/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:50:08 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 17:24:23 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Array.tpp"

int	main(void)
{
	Array<int> first;
	Array<double> second(10);
	
	std::cout << std::endl;
	std::cout << RESET << YELLOW_B << "size of first array = " << first.size() << RESET << std::endl;
	std::cout << RESET << YELLOW_B << "size of second array = " << second.size() << RESET << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	try {
		second[4] = 12.4;
		std::cout << RESET << RED_B << "fourth of second array = " << second[4] << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "error occured because : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << std::endl;
	try {
		second[0] = 12;
		std::cout << RESET << RED_B << "tenth of second array = " << second[4] << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "error occured because : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	Array<double>	copy;
	copy = second;
	std::cout << std::endl;
	try {
		std::cout << RESET << RED_B << "fourth of copy array = " << second[4] << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "error occured because : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
}
