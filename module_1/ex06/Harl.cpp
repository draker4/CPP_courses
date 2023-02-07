/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:58:04 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/07 18:06:14 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "love having extra bacon for my 7XL-double-cheese-triple-pickle-special ketchup burger. I really do!" << std::endl;
	std::cout << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	std::cout << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
	std::cout << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	std::cout << std::endl;
}

void	Harl::complain(std::string level)
{
	int	i = -1;
	int	index = 4;
	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (++i < 4)
		if (!level.compare(levels[i]))
		{
			index = i;
			break ;
		}
	switch (index)
	{
		case 0:
			this->debug();
			//fall through
		case 1:
			this->info();
			//fall through
		case 2:
			this->warning();
			//fall through
		case 3:
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
