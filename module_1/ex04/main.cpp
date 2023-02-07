/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 15:30:29 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/07 17:11:03 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string	sed(std::string lines, std::string to_find, std::string to_remplace)
{
	std::size_t pos = 0;

	if (lines.empty())
		return NULL;
	if (to_find.empty() || to_remplace.empty())
		return (lines);
	pos = lines.find(to_find, pos);
	while (pos != std::string::npos)
	{
		lines.erase(pos, to_find.length());
		lines.insert(pos, to_remplace);
		pos = lines.find(to_find, pos + 1);
	}
	return (lines);
}

int	main(int argc, char **argv)
{
	std::string	lines;
	const std::string red("\033[1;31m");
	const std::string reset("\033[0m");

	if (argc != 4)
	{
		std::cerr << red << "Please enter only three parameters in the following order: a filename and two strings" << reset << std::endl;
		return (1);
	}
	
	std::ifstream	ifs(argv[1], std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cerr << "Could not open " << argv[1] << std::endl;
		return (1);
	}
	
	if (!std::getline(ifs, lines, '\0'))
	{
		ifs.close();
		std::cout << red << "Getline function error" << reset << std::endl;
		return (1);
	}
	else
	{
		ifs.close();
		std::ofstream	ofs((argv[1] + std::string(".replace")).c_str(), std::ofstream::out | std::ofstream::trunc);
		if (!ofs.is_open())
		{
			std::cout << red << "Getline function error" << reset << std::endl;
			return (EXIT_FAILURE);
		}
		ofs << sed(lines, argv[2], argv[3]) << std::flush;
		ofs.close();
	}
	
	return (0);
}
