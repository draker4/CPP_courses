/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:13:38 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/06 15:08:30 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <ios>
#include <limits>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	cmd;

	phoneBook.begin();
	while (cmd.compare("EXIT"))
	{
		std::cout << " > " << std::flush;
		std::getline(std::cin, cmd);
		if (!cmd.compare("ADD"))
			phoneBook.add();
		else if (!cmd.compare("SEARCH"))
			std::cout << "search command" << std::endl;
		else
			std::cout << cmd << " is not a valid command." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "Thanks for using this amazing PhoneBook, see you soon!" << std::endl;
	return (0);
}
