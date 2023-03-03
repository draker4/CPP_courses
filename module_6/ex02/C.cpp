/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:11:30 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 13:51:41 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "C.hpp"
#include "colors.hpp"

// destructor

C::~C(void)
{
	std::cout << RED_F << "Default C destructor" << RESET << std::endl;
}

// constructor

C::C(void)
{
	std::cout << RED_F << "Default C contructor" << RESET << std::endl;
}

C::C(const C &rhs) : Base(rhs)
{
	*this = rhs;
	std::cout << RED_F << "Copy C constructor" << RESET << std::endl;
}

// operCtor overloCds

C &C::operator = (const C &rhs)
{
	(void)rhs;
	std::cout << RED_F << "Copy C Assignement operator" << RESET << std::endl;
	return *this;
}
