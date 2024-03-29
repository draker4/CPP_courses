/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:40:23 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/27 20:09:37 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include "colors.hpp"

// destructors - constructors

Ice::~Ice(void)
{
	std::cout << BLUE_F << "Default Ice destructor called" << std::endl;
}

Ice::Ice(void) : AMateria("ice")
{
	std::cout << BLUE_F << "Default Ice constructor called" << std::endl;
}

Ice::Ice(const Ice &rhs) : AMateria(rhs)
{
	*this = rhs;
	std::cout << BLUE_F << "Copy Ice constructor called" << std::endl;
}

// operator overloads

Ice	&Ice::operator=(const Ice &rhs)
{
	_type = rhs._type;
	std::cout << BLUE_F << "Copy Ice assignement operator called" << std::endl;
	return (*this);
}

// member functions

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
