/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:34:53 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/24 14:32:09 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "colors.hpp"

// Constructors - destructors

Animal::~Animal(void)
{
	std::cout << MAGENTA_F << "Default Animal destructor called" << RESET << std::endl;
}

Animal::Animal(void)
{
	std::cout << MAGENTA_F << "Default Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &rhs)
{
	*this = rhs;
	std::cout << MAGENTA_F << "Copy Animal constructor called" << std::endl;
}

// operator

Animal	&Animal::operator=(const Animal &rhs)
{
	_type = rhs._type;
	std::cout << MAGENTA_F << "Copy assignement Animal operator called" << std::endl;
	return *this;
}

// getter

std::string	Animal::getType(void) const
{
	return _type;
}

// functions

void	Animal::makeSound(void) const
{
	std::cout << MAGENTA_F << "Animal makes sound" << std::endl;
}
