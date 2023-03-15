/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:20:55 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/15 16:38:24 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iterator>
#include <sys/time.h>
#include <unistd.h>
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
	std::map<int, int>::iterator	end_it;
	
	for (std::map<int,int>::iterator it = map.begin(); it != map.end(); it++)
	{
		_map[it->first] = it->second;
		_map_origin[it->first] = it->second;
		end_it = it;
	}
	
	struct timeval	time_start;
	struct timeval	time_end;
	gettimeofday(&time_start, NULL);
	mergeSortMap(_map.begin(), end_it);
	gettimeofday(&time_end, NULL);
	if (time_end.tv_sec == time_start.tv_sec)
		_time = time_end.tv_usec - time_start.tv_usec;
	else
	{
		_time = (time_end.tv_sec - (time_start.tv_sec + 1)) * 1000000;
		_time += 1000000 - time_start.tv_usec;
		_time += time_end.tv_usec;
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
	struct timeval	time_start;
	struct timeval	time_end;
	gettimeofday(&time_start, NULL);
	mergeSortDeque(_deque.begin(), _deque.end() - 1);
	gettimeofday(&time_end, NULL);
	if (time_end.tv_sec == time_start.tv_sec)
		_time = time_end.tv_usec - time_start.tv_usec;
	else
	{
		_time = (time_end.tv_sec - (time_start.tv_sec + 1)) * 1000000;
		_time += 1000000 - time_start.tv_usec;
		_time += time_end.tv_usec;
	}
	// std::cout << RED_F << "Map PmergeMe constructor called" << RESET << std::endl;
}

void	PmergeMe::mergeSortMap(std::map<int, int>::iterator begin, std::map<int, int>::iterator end)
{
	if (begin->first >= end->first)
		return ;
	std::map<int, int>::iterator	med = _map.find(begin->first + (end->first - begin->first) / 2);
	mergeSortMap(begin, med);
	mergeSortMap(++med, end);
	mergeMap(begin, --med, end);
}

void	PmergeMe::mergeMap(std::map<int, int>::iterator left, std::map<int, int>::iterator med, std::map<int, int>::iterator right)
{
	std::map<int, int>	leftMap;
	std::map<int, int>	rightMap;
	int					size_left = med->first - left->first + 1;
	int					size_right = right->first - med->first;

	for (int i = 0; i < size_left; ++i)
		leftMap[i] = _map[left->first + i];
	for (int i = 0;i < size_right; ++i)
		rightMap[i] = _map[med->first + 1 + i];
	
	std::map<int, int>::iterator	l_it = leftMap.begin();
	std::map<int, int>::iterator	r_it = rightMap.begin();
	
	while (l_it != leftMap.end() && r_it != rightMap.end())
	{
		if (l_it->second <= r_it->second)
		{
			left->second = l_it->second;
			l_it++;
		}
		else
		{
			left->second = r_it->second;
			r_it++;
		}
		left++;
	}
	while (l_it != leftMap.end())
	{
		left->second = l_it->second;
		left++;
		l_it++;
	}
	while (r_it != rightMap.end())
	{
		left->second = r_it->second;
		left++;
		r_it++;
	}
}

void	PmergeMe::mergeSortDeque(std::deque<int>::iterator begin, std::deque<int>::iterator end)
{
	if (begin >= end)
		return ;
	std::deque<int>::iterator	med = begin + (end - begin) / 2;
	mergeSortDeque(begin, med);
	mergeSortDeque(med + 1, end);
	mergeDeque(begin, med, end);
}

void	PmergeMe::mergeDeque(std::deque<int>::iterator left, std::deque<int>::iterator med, std::deque<int>::iterator right)
{
	std::deque<int>	leftDeque;
	std::deque<int>	rightDeque;
	int	size_left = med - left + 1;
	int	size_right = right - med;

	for (int i = 0; i < size_left; ++i)
		leftDeque.push_back(*(left + i));
	for (int i = 0; i < size_right; ++i)
		rightDeque.push_back(*(med + 1 + i));
	
	std::deque<int>::iterator	l_it = leftDeque.begin();
	std::deque<int>::iterator	r_it = rightDeque.begin();
	
	while (l_it != leftDeque.end() && r_it != rightDeque.end())
	{
		if (*l_it <= *r_it)
		{
			*left = *l_it;
			l_it++;
		}
		else
		{
			*left = *r_it;
			r_it++;
		}
		left++;
	}
	while (l_it != leftDeque.end())
	{
		*left = *l_it;
		left++;
		l_it++;
	}
	while (r_it != rightDeque.end())
	{
		*left = *r_it;
		left++;
		r_it++;
	}
}

void    PmergeMe::print_init(void) const
{
	if (_container == 1)
	{
		for (std::map<int, int>::const_iterator it = _map_origin.begin(); it != _map_origin.end(); it++)
		{
			std::cout << MAGENTA_F << it->second;
			std::map<int, int>::const_iterator it2 = it;
			if (++it2 != _map_origin.end())
				std::cout << " - ";
		}
		std::cout << RESET << std::endl;
	}
	else if (_container == 2)
	{
		for (std::deque<int>::const_iterator it = _deque_origin.begin(); it != _deque_origin.end(); it++)
		{
			std::cout << MAGENTA_F << *it;
			std::deque<int>::const_iterator it2 = it;
			if (++it2 != _deque_origin.end())
				std::cout << " - ";
		}
		std::cout << RESET << std::endl;
	}
}

void    PmergeMe::print_sort(void) const
{
	if (_container == 1)
	{
		for (std::map<int, int>::const_iterator it = _map.begin(); it != _map.end(); it++)
		{
			std::cout << MAGENTA_F << it->second;
			std::map<int, int>::const_iterator it2 = it;
			if (++it2 != _map.end())
				std::cout << " - ";
		}
		std::cout << RESET << std::endl;
	}
	else if (_container == 2)
	{
		for (std::deque<int>::const_iterator it = _deque.begin(); it != _deque.end(); it++)
		{
			std::cout << MAGENTA_F << *it;
			std::deque<int>::const_iterator it2 = it;
			if (++it2 != _deque.end())
				std::cout << " - ";
		}
		std::cout << RESET << std::endl;
	}
}

void    PmergeMe::print_time(void) const
{
	std::cout << MAGENTA_F << _time << RESET;
}
