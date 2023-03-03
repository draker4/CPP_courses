/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:11:30 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 13:51:29 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "colors.hpp"

//destructor

A::~A(void)
{
	std::cout << RED_F << "Default A destructor" << RESET << std::endl;
}

// constructor

A::A(void)
{
	std::cout << RED_F << "Default A contructor" << RESET << std::endl;
}

A::A(const A &rhs) : Base(rhs)
{
	*this = rhs;
	std::cout << RED_F << "Copy A constructor" << RESET << std::endl;
}

// operator overloads

A	&A::operator=(const A &rhs)
{
	(void)rhs;
	std::cout << RED_F << "Copy A assignement operator" << RESET << std::endl;
	return *this;
}
