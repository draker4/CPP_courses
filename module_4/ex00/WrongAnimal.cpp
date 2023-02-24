/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:34:53 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/24 14:50:31 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "colors.hpp"

// Constructors - destructors

WrongAnimal::~WrongAnimal(void)
{
	std::cout << MAGENTA_F << "Default WrongAnimal destructor called" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(void)
{
	std::cout << MAGENTA_F << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &rhs)
{
	*this = rhs;
	std::cout << MAGENTA_F << "Copy WrongAnimal constructor called" << std::endl;
}

// operator

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	_type = rhs._type;
	std::cout << MAGENTA_F << "Copy assignement WrongAnimal operator called" << std::endl;
	return *this;
}

// getter

std::string WrongAnimal::getType(void) const
{
	return _type;
}

// functions

void WrongAnimal::makeSound(void) const
{
	std::cout << MAGENTA_F << "WrongAnimal makes sound" << std::endl;
}
