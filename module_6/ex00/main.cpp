/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:27:34 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/02 12:10:42 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "colors.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cerr << RED_B << "Please enter one argument and one only!" << RESET << std::endl;
	std::cout << std::endl;
	return 0;
}