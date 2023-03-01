/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:22:52 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/01 11:31:18 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include "colors.hpp"

// destructors - constructors

AMateria::~AMateria(void)
{
	std::cout << RED_F << "Default AMateria destructor called" << std::endl;
}

AMateria::AMateria(void) : _type(""), _equip(false)
{
	std::cout << RED_F << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type), _equip(false)
{
	std::cout << RED_F << "String AMateria constructor called" << std::endl;
}

AMateria::AMateria(const AMateria &rhs)
{
	*this = rhs;
	std::cout << RED_F << "Copy AMateria constructor called" << std::endl;
}

// operator overloads

AMateria	&AMateria::operator=(const AMateria &rhs)
{
	_equip = rhs._equip;
	std::cout << RED_F << "Copy AMateria assignement operator called" << std::endl;
	return (*this);
}

// getter - setter

std::string const	&AMateria::getType() const
{
	return _type;
}

bool	AMateria::getEquip(void) const
{
	return _equip;
}

void	AMateria::setEquip(bool equip)
{
	_equip = equip;
}

// member functions

void	AMateria::use(ICharacter &target)
{
	std::cout << "use of " << _type << " on " << target.getName() << std::endl;
}
