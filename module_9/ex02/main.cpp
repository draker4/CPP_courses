/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:37:10 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/14 22:09:47 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>
#include <cstdlib>

int	main(int argc, char **argv)
{
	std::map<int, int>	map;
	std::deque<int>		deque;

	if (argc < 1)
	{
		std::cout << YELLOW_B << "Error" << RESET << std::endl;
	}
	for (int i = 1; i < argc; i++)
	{
		if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
		{
			std::cout << YELLOW_B << "Error" << RESET << std::endl;
			return 1;
		}
		double	nb = strtod(argv[i], NULL);
		if (errno == ERANGE || nb > INT_MAX)
		{
			std::cout << YELLOW_B << "Error" << RESET << std::endl;
			return 1;
		}
		map[i] = nb;
		deque.push_back(nb);
	}
	PmergeMe	test_map(map);
	PmergeMe	test_deque(deque);
	return 0;
}
