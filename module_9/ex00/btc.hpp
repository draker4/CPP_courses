/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btc.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:42:53 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/15 17:07:56 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <vector>
#include <exception>
#include <cstdlib>

class	BadInput : public std::exception
{
	private:
		std::string	_str;
	
	public:
		BadInput(std::string s) {
			std::ostringstream	o;
			o << "Error: bad input => " << s;
			_str = o.str();
		}
		~BadInput(void) throw() {};
		virtual const char	*what() const throw() { return _str.c_str(); }
};

class	NegNumber : public std::exception
{
	public:
		virtual const char	*what() const throw() { return "Error: not a positive number."; }
};

class	TooLarge : public std::exception
{
	public:
		virtual const char	*what() const throw() { return "Error: too large a number."; }
};

static double	getExchangeRate(std::string s, std::string date, std::vector<BitcoinExchange> vec)
{
	double				year;
	double				month;
	double				day;
	char				dash;
	std::stringstream	ss(date);

	if (date.find_first_not_of("0123456789- ") != std::string::npos)
		throw BadInput(s);
	if (date.find("--") != std::string::npos || date[date.length() - 1] == '-')
		throw BadInput(s);
	ss >> year >> dash >> month >> dash >> day;
	if (year < 2009 || year > 2022 || month <= 0 || month > 12 || day <= 0 || day > 31)
		throw BadInput(s);
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

static double	getValue(std::string s, std::string value)
{
	if (value.find_first_not_of("-0123456789., ") != std::string::npos || value.find_first_of("-") != value.find_last_of("-") || value.find_first_of(",") != value.find_last_of(","))
		throw BadInput(s);
	if (value.find_first_of(",") != std::string::npos)
		value.replace(value.find_first_of(","), 1, ".");
	if (value.find_first_of("-") != std::string::npos && value[1] != '-')
		throw BadInput(s);
	else if (value.find_first_of("-") != std::string::npos)
		throw NegNumber();

	double	val = strtod(value.c_str(), NULL);
	if (errno == ERANGE || val > 1000)
		throw TooLarge();
	return val;
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
		throw BadInput(s);
	date = s.substr(0, pos);
	exchange_rate = getExchangeRate(s, date, vec);
	value = getValue(s, s.substr(pos + 1, s.length() - pos));
	
	std::cout << CYAN_F << date << "=> " << value << " = " << value * exchange_rate << RESET << std::endl;
}
