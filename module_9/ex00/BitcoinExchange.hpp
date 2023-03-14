/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:18:51 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/14 15:48:38 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <sstream>
# include "colors.hpp"

class	BitcoinExchange
{
	private:
	
		BitcoinExchange(void);
		
		int			_year;
		int			_month;
		int			_day;
		double		_exchange_rate;
	
	public:
	
		BitcoinExchange(std::string s);
		BitcoinExchange(const BitcoinExchange &rhs);
		~BitcoinExchange(void);
		
		BitcoinExchange	&operator=(const BitcoinExchange &rhs);
		
		int			getYear(void) const;
		int			getMonth(void) const;
		int			getDay(void) const;
		double		getExchangeRate(void) const;
};

#endif
