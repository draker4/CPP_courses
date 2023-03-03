/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:11:30 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 13:51:38 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "B.hpp"
#include "colors.hpp"

// destructor

B::~B(void)
{
	std::cout << RED_F << "Default B destructor" << RESET << std::endl;
}

// constructor

B::B(void)
{
	std::cout << RED_F << "Default B contructor" << RESET << std::endl;
}

B::B(const B &rhs) : Base(rhs)
{
	*this = rhs;
	std::cout << RED_F << "Copy B constructor" << RESET << std::endl;
}

// operBtor overloBds

B &B::operator = (const B &rhs)
{
	(void)rhs;
	std::cout << RED_F << "Copy B assignement operator" << RESET << std::endl;
	return *this;
}
