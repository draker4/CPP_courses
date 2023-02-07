/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:57:20 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/07 18:01:37 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <stdlib.h>

int	main(int	argc, char **argv)
{
	Harl	harl;

	if (argc == 1)
	{
		std::cout << "Please enter at least one argument!" << std::endl;
		return (1);
	}
	if (argc != 2)
	{
		std::cout << "Please enter one argument only!" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}
