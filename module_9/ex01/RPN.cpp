/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:41:44 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/15 18:31:10 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <climits>

// destructor

RPN::~RPN(void)
{
	std::cout << CYAN_F << "Default RPN destructor" << RESET << std::endl;
}

// constructor

RPN::RPN(void)
{
	std::cout << CYAN_F << "Default RPN constructor" << RESET << std::endl;
}

RPN::RPN(std::string s)
{
	int	i = -1;

	while (s[++i])
	{
		if (s[i] >= 48 && s[i] <= 57)
			_list.push_back(s[i] - 48);
		else if (s[i] != ' ')
		{
			switch (s[i])
			{
				case '*':
					multiply();
					break ;
				case '+':
					addition();
					break ;
				case '-':
					substract();
					break;
				case '/':
					divide();
					break ;
				default:
					throw WrongChar();
			}
		}
	}
	std::cout << CYAN_F << "Default RPN constructor" << RESET << std::endl;
}

RPN::RPN(const RPN &rhs)
{
	*this = rhs;
	std::cout << CYAN_F << "Copy RPN constructor" << RESET << std::endl;
}

// operator overload

RPN	&RPN::operator=(const RPN &rhs)
{
	_list.clear();
	for (std::list<int>::const_iterator it = rhs._list.begin(); it != rhs._list.end(); it++)
		_list.push_back(*it);
	std::cout << CYAN_F << "Copy RPN operator assignement" << RESET << std::endl;
	return *this;
}

// member function

void	RPN::addition(void)
{
	if (_list.size() < 2)
		throw NotEnoughNumbers();
	
	double	check;

	int	b = _list.back();
	_list.pop_back();
	int	a = _list.back();
	_list.pop_back();
	check = a + b;
	if (check < INT_MIN || check > INT_MAX)
		throw IntOutOfRange();
	else
		_list.push_back(a + b);
}

void	RPN::substract(void)
{
	if (_list.size() < 2)
		throw NotEnoughNumbers();
	
	double	check;
	int	b = _list.back();
	_list.pop_back();
	int	a = _list.back();
	_list.pop_back();
	check = a - b;
	if (check < INT_MIN || check > INT_MAX)
		throw IntOutOfRange();
	else
		_list.push_back(a - b);
}

void	RPN::multiply(void)
{
	if (_list.size() < 2)
		throw NotEnoughNumbers();
	
	double	check;
	int	b = _list.back();
	_list.pop_back();
	int	a = _list.back();
	_list.pop_back();
	check = a * b;
	if (check < INT_MIN || check > INT_MAX)
		throw IntOutOfRange();
	else
		_list.push_back(a * b);
}

void	RPN::divide(void)
{
	if (_list.size() < 2)
		throw NotEnoughNumbers();
	
	double	check;
	int	b = _list.back();
	if (b == 0)
		throw DivisionByZero();
	_list.pop_back();
	int	a = _list.back();
	_list.pop_back();
	check = a / b;
	if (check < INT_MIN || check > INT_MAX)
		throw IntOutOfRange();
	else
		_list.push_back(a / b);
}

// getter

int	RPN::getBack(void) const
{
	if (!_list.empty())
		return _list.back();
	return 0;
}

// non member functions

std::ostream	&operator<<(std::ostream &o, const RPN &rhs)
{
	o << rhs.getBack();
	return o;
}
