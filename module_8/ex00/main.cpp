/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:22:23 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/15 18:27:57 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "easyfind.hpp"
#include <vector>
#include <iostream>

int	main(void)
{
	std::vector<int> v;

	v.push_back(0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	
	try {
		int a = easyfind(v, 2);
		std::cout << a << std::endl; 
	}
	catch (std::exception &e) {
		std::cout << e.what();
	}

	try {
		int a = easyfind(v, 12);
		std::cout << a << std::endl; 
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
