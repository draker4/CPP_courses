/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 13:59:57 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/21 15:28:20 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <vector>

void	btc(std::string s, std::vector<BitcoinExchange> vec);

int	main(int argc, char **argv)
{
	// check number of args
	if (argc != 2)
	{
		std::cout << MAGENTA_B << BOLD << "Error: enter ONE file name." << RESET << std::endl;
		return 1;
	}
	
	std::vector<BitcoinExchange>	vec;
	
	// stock database in BitcoinExchange
	std::string		line_data;
	std::ifstream	ifs_data("data.csv");
	if (!ifs_data.is_open())
	{
		std::cout << MAGENTA_B << BOLD << "Error: database not found." << RESET << std::endl;
		return 1;
	}
	while (std::getline(ifs_data, line_data, '\n'))
	{
		if (!line_data.compare("date,exchange_rate"))
			continue;
		BitcoinExchange	bitcoin(line_data);
		vec.push_back(bitcoin);
	}
	ifs_data.close();
	
	// open input file
	std::ifstream	ifs_input(argv[1]);
	if (!ifs_input.is_open())
	{
		std::cout << MAGENTA_B << BOLD << "Error: could not open file." << RESET << std::endl;
		return 1;
	}
	
	// read input file
	std::string	line;
	while (std::getline(ifs_input, line, '\n'))
	{
		try {
			btc(line, vec);
		}
		catch (std::exception	&e) {
			std::cout << CYAN_F << e.what() << std::endl;
		}
	}
	ifs_input.close();

	return 0;
}
