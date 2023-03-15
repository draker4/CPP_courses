/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:41:41 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/15 17:56:30 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include "colors.hpp"
# include <list>

class	RPN
{
	private:
	
		RPN(void);
		std::list<int>	_list;
		
		void			addNumber(int nb);
		void			multiply(void);
		void			addition(void);
		void			substract(void);
		void			divide(void);
	
	public:
	
		RPN(std::string s);
		RPN(const RPN &rhs);
		~RPN(void);

		RPN	&operator=(const RPN &rhs);
		
		int				getBack(void) const;

		class	WrongChar : public std::exception {
			public:
				 virtual const char	*what() const throw() { return "Wrong character entered."; }
		};
		
		class	NotEnoughNumbers : public std::exception {
			public:
				 virtual const char	*what() const throw() { return "Not enough numbers entered before the operation."; }
		};
		
		class	DivisionByZero : public std::exception {
			public:
				 virtual const char	*what() const throw() { return "Can not divide by zero."; }
		};
		
		class	IntOutOfRange : public std::exception {
			public:
				 virtual const char	*what() const throw() { return "Result not in integer range."; }
		};
};

std::ostream	&operator<<(std::ostream &o, const RPN &rhs);

#endif
