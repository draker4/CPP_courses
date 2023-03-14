/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:20:55 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/14 22:07:17 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// destructor

PmergeMe::~PmergeMe(void)
{
	// std::cout << RED_F << "Default PmergeMe destructor called" << RESET << std::endl;
}

// constructor

PmergeMe::PmergeMe(void) : _time(0), _container(0)
{
	// std::cout << RED_F << "Default PmergeMe constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(std::map<int,int> map) : _time(0), _container(1)
{
	for (std::map<int,int>::const_iterator it = map.begin(); it != map.end(); it++)
	{
		_map[it->first] = it->second;
		_map_origin[it->first] = it->second;
	}
	// std::cout << RED_F << "Map PmergeMe constructor called" << RESET << std::endl;
}

PmergeMe::PmergeMe(std::deque<int> deque) : _time(0), _container(2)
{
	for (std::deque<int>::const_iterator it = deque.begin(); it != deque.end(); it++)
	{
		_deque.push_back(*it);
		_deque_origin.push_back(*it);
	}
	// std::cout << RED_F << "Map PmergeMe constructor called" << RESET << std::endl;
}
