/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:52:57 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/01 11:24:38 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "colors.hpp"

// destructors - constructors

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	std::cout << WHITE_F << "Default MateriaSource destructor called" << std::endl;
}

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << WHITE_F << "Default MateriaSource constructor called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &rhs)
{
	*this = rhs;
	std::cout << WHITE_F << "Copy MateriaSource constructor called" << std::endl;
}

// operator overloads

MateriaSource	&MateriaSource::operator=(const MateriaSource &rhs)
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	for (int i = 0; i < 4; i++)
		_inventory[i] = rhs._inventory[i]->clone();
	std::cout << WHITE_F << "Copy MateriaSource assignement operator called" << std::endl;
	return (*this);
}

// member functions

void	MateriaSource::learnMateria(AMateria *m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for(int i = 0; i < 4; i++) 
	{
		if (_inventory[i] !=  NULL)
			if (_inventory[i]->getType() == type)
				return _inventory[i]->clone();
	}
	return NULL;
}
