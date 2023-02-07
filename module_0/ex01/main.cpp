/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:13:38 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/07 10:24:44 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iostream>

int	main(void)
{
	PhoneBook	phoneBook;
	std::string	cmd;

	phoneBook.begin();
	while (cmd.compare("EXIT"))
	{
		std::cout << " > " << std::flush;
		std::getline(std::cin, cmd);
		if (std::cin.eof())
			break ;
		if (!cmd.compare("ADD"))
			phoneBook.add();
		else if (!cmd.compare("SEARCH"))
			phoneBook.search();
		else if (cmd.compare("EXIT"))
			std::cout << cmd << " is not a valid command." << std::endl;
	}
	std::cout << "Thanks for using this amazing PhoneBook, see you soon!" << std::endl;
	return (0);
}
