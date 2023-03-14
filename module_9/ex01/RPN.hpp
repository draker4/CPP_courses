/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:41:41 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/14 20:53:48 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include "colors.hpp"
# include <stack>

class	RPN
{
	private:
	
		RPN(void);
		std::stack<int>	_stack;
	
	public:
	
		RPN(std::string s);
		RPN(const RPN &rhs);
		~RPN(void);

		RPN	&operator=(const RPN &rhs);
};

#endif
