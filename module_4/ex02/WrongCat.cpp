/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:44:36 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/02 14:29:38 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "colors.hpp"

// constructors - destrcutor

WrongCat::~WrongCat(void)
{
	std::cout << YELLOW_F << "Default WrongCat destructor called" << RESET << std::endl;
}

WrongCat::WrongCat(void)
{
	_type = "WrongCat";
	std::cout << YELLOW_F << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs) : WrongAnimal(rhs)
{
	*this = rhs;
	std::cout << YELLOW_F << "Copy WrongCat constructor called" << std::endl;
}

// operator

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	_type = rhs._type;
	std::cout << YELLOW_F << "Copy assignement WrongCat operator called" << std::endl;
	return *this;
}

// functions

void WrongCat::makeSound(void) const
{
	std::cout << YELLOW_F << "WrongCat says MIAOU" << std::endl;
}
