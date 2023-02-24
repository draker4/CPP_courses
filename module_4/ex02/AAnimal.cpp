/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:34:53 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/24 15:52:44 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "colors.hpp"

// Constructors - destructors

AAnimal::~AAnimal(void)
{
	std::cout << MAGENTA_F << "Default AAnimal destructor called" << RESET << std::endl;
}

AAnimal::AAnimal(void)
{
	std::cout << MAGENTA_F << "Default AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &rhs)
{
	*this = rhs;
	std::cout << MAGENTA_F << "Copy AAnimal constructor called" << std::endl;
}

// operator

AAnimal	&AAnimal::operator=(const AAnimal &rhs)
{
	_type = rhs._type;
	std::cout << MAGENTA_F << "Copy assignement AAnimal operator called" << std::endl;
	return *this;
}

// getter

std::string	AAnimal::getType(void) const
{
	return _type;
}

// functions

void	AAnimal::makeSound(void) const
{
	std::cout << MAGENTA_F << "AAnimal makes sound" << std::endl;
}
