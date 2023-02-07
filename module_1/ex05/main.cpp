/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:57:20 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/07 17:49:13 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	std::string	level;
	Harl		harl;

	std::cout << "Please enter 'DEBUG', 'INFO', 'WARNING', 'ERROR' or write 'EXIT' to stop" << std::endl;
	while (1)
	{
		std::cout << " > " << std::flush;
		std::getline(std::cin, level);
		if (std::cin.eof() || !level.compare("EXIT"))
			break ;
		harl.complain(level);
	}
	return (0);
}
