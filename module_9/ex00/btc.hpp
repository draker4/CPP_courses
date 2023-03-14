/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:42:53 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/14 16:53:47 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static double	getExchangeRate(std::string date, std::vector<BitcoinExchange> vec)
{
	double				year;
	double				month;
	double				day;
	char				dash;
	std::stringstream	ss(date);

	if (date.find_first_not_of("0123456789- ") != std::string::npos)
		return -1;
	if (date.find("--") != std::string::npos || date[date.length() - 1] == '-')
		return -1;
	ss >> year >> dash >> month >> dash >> day;
	if (year < 2009 || year > 2022 || month <= 0 || month > 12 || day <= 0 || day > 31)
		return -1;
	for (std::vector<BitcoinExchange>::const_iterator it = vec.begin(); it != vec.end(); it++)
	{
		if (year < it->getYear() || (year == it->getYear() && month < it->getMonth()) || (year == it->getYear() && month == it->getMonth() && day < it->getDay()))
		{
			if (it != vec.begin())
				return (it - 1)->getExchangeRate();
			else
				return it->getExchangeRate();
		}
	}
	return (vec.end() - 1)->getExchangeRate();
}

void	btc(std::string s, std::vector<BitcoinExchange> vec)
{
	std::string	date;
	double		exchange_rate;
	double		value;

	if (!s.compare("date | value") || vec.empty())
		return ;
	std::string::size_type	pos = s.find_first_of("|");
	if (pos == std::string::npos || pos != s.find_last_of("|") || s[0] == '|' || s[s.length() - 1] == '|')
	{
		std::cout << CYAN_F << "Error: bad input => " << s << RESET << std::endl;
		return ;
	}
	else
		date = s.substr(0, pos);
	exchange_rate = getExchangeRate(date, vec);
	if (exchange_rate == -1)
	{
		std::cout << CYAN_F << "Error: bad input => " << s << RESET << std::endl;
		return ;
	}
	//value
	std::cout << CYAN_F << date << " " << exchange_rate << RESET << std::endl;
}
