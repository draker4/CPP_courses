/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:45:47 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/14 20:51:47 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << MAGENTA_F << "Error: wrong number of arguments." << RESET << std::endl;
		return 1;
	}
	std::string	str(argv[1]);
	if (str.find_first_not_of("0123456789 +-*\\") != std::string::npos)
	{
		std::cout << MAGENTA_F << "Error: wrong characters." << RESET << std::endl;
		return 1;
	}
	RPN(str);
	return 0;
}
