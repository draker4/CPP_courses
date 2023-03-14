/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:18:37 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/14 15:49:00 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// destructor

BitcoinExchange::~BitcoinExchange(void)
{
	// std::cout << GREEN_F << "Default BitcoinExchange destructor" << RESET << std::endl;
}

// constructor

BitcoinExchange::BitcoinExchange(void) : _year(0), _month(0), _day(0), _exchange_rate(0)
{
	// std::cout << GREEN_F << "Default BitcoinExchange constructor" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(std::string str)
{
	std::stringstream	ss(str);
	char				dash;
	
	ss >> _year >> dash >> _month >> dash >> _day >> dash >> _exchange_rate;
	// std::cout << GREEN_F << "String BitcoinExchange constructor" << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs) : _year(rhs._year), _month(rhs._month), _day(rhs._day), _exchange_rate(rhs._exchange_rate)
{
	// std::cout << GREEN_F << "Copy BitcoinExchange constructor" << RESET << std::endl;
}

// operator overload

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	_year = rhs._year;
	_month = rhs._month;
	_day = rhs._day;
	_exchange_rate = rhs._exchange_rate;
	// std::cout << GREEN_F << "Copy BitcoinExchange assignement operator" << RESET << std::endl;
	return *this;
}

// getters

int	BitcoinExchange::getYear(void) const
{
	return _year;
}

int	BitcoinExchange::getMonth(void) const
{
	return _month;
}

int	BitcoinExchange::getDay(void) const
{
	return _day;
}

double	BitcoinExchange::getExchangeRate(void) const
{
	return _exchange_rate;
}
