/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:35:04 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/15 16:55:52 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "colors.hpp"
#include <algorithm>

// destructor

Span::~Span(void)
{
	std::cout << CYAN_F << "Default Span destructor" << RESET << std::endl; 
}

// constructor

Span::Span(void) : _N(0)
{
	std::cout << CYAN_F << "Default Span constructor" << RESET << std::endl;
}

Span::Span(unsigned int N) : _N(N)
{
	std::cout << CYAN_F << "Unsigned int Span constructor" << RESET << std::endl;
}

Span::Span(const Span &rhs)
{
	*this = rhs;
	std::cout << CYAN_F << "Copy Span constructor" << RESET << std::endl;
}

// operator overloads

Span	&Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_N = rhs._N;
		_vec = rhs._vec;
	}
	std::cout << CYAN_F << "Copy Span operator assignement" << RESET << std::endl;
	return *this;
}

// getter setter

unsigned int	Span::getN(void) const
{
	return _N;
}

// member function

void	Span::addNumber(int n)
{
	if (_vec.size() >= _N)
		throw ContainerFull();
	_vec.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end)
{
	for (std::vector<int>::iterator it = it_begin; it != it_end; it++)
		addNumber(*it);
}

void	Span::printList(std::ostream &o) const
{
	for (std::vector<int>::const_iterator	it = _vec.begin(); it != _vec.end(); it++)
	{
		o << *it;
		if (it != _vec.end() - 1)
			o << " - ";
	}
}

int	Span::shortestSpan(void)
{
	std::vector<int>::const_iterator	it = _vec.begin();
	int									min;

	if (_vec.size() <= 1)
		throw SizeTooLow();
	sort(_vec.begin(), _vec.end());
	min = abs(*(it + 1) - *it);
	for (it = _vec.begin(); it != _vec.end(); it++)
	{
		if ((it + 1) != _vec.end() && abs(*(it + 1) - *it) < min)
			min = abs(*(it + 1) - *it);
	}
	return min;
}

int	Span::longestSpan(void)
{
	std::vector<int>::const_iterator	it = _vec.begin();
	int									min;
	int									max;

	if (_vec.size() <= 1)
		throw SizeTooLow();
	min = *it;
	max = *it;
	for (it = _vec.begin(); it != _vec.end(); it++)
	{
		if (*it < min)
			min = *it;
		if (*it > max)
			max = *it;
	}
	return (max - min);
}

// non member function

std::ostream	&operator<<(std::ostream &o, const Span &rhs)
{
	o << "Span contains the following numbers : ";
	rhs.printList(o);
	return o;
}
