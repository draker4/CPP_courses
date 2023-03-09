/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:35:04 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/09 12:14:14 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "colors.hpp"

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

void	Span::printList(std::ostream &o) const
{
	for (std::vector<int>::const_iterator	it = _vec.begin(); it != _vec.end(); it++)
	{
		o << *it;
		if (it != _vec.end() - 1)
			o << " - ";
	}
}

int	Span::shortestSpan(void) const
{
	int	min;
	int	max;

	if (_vec.size() <= 1)
		throw SizeTooLow();
	
}

// non member function

std::ostream	&operator<<(std::ostream &o, const Span &rhs)
{
	o << "Span contains the following numbers : ";
	rhs.printList(o);
	return o;
}
