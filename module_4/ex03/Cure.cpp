/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:40:23 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/27 15:15:11 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "colors.hpp"

// destructors - constructors

Cure::~Cure(void)
{
	std::cout << BLUE_F << "Default Cure destructor called" << std::endl;
}

Cure::Cure(void) : AMateria("cure")
{
	std::cout << BLUE_F << "Default Cure constructor called" << std::endl;
}

Cure::Cure(const Cure &rhs)
{
	*this = rhs;
	std::cout << BLUE_F << "Copy Cure constructor called" << std::endl;
}

// operator overloads

Cure	&Cure::operator=(const Cure &rhs)
{
	_type = rhs._type;
	std::cout << BLUE_F << "Copy Cure assignement operator called" << std::endl;
	return (*this);
}

// member functions

AMateria	*Cure::clone(const Cure &rhs)
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
