/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:49:59 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/02 14:35:13 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Ground.hpp"
#include "colors.hpp"

// destructor

Ground::~Ground(void)
{
	for (int i = 0; i < 10; i++)
		delete _inventory[i];
	std::cout << YELLOW_F << "Default Ground destructor called" << RESET << std::endl;
}

// constructor

Ground::Ground(void)
{
	for (int i = 0; i < 10; i++)
		_inventory[i] = NULL;
	std::cout << YELLOW_F << "Default Ground constructor called" << std::endl;
}

Ground::Ground(const Ground &rhs)
{
	*this = rhs;
	std::cout << YELLOW_F << "Copy Ground constructor called" << std::endl;
}

Ground	&Ground::operator=(const Ground &rhs)
{
	for (int i = 0; i < 10; i++)
		_inventory[i] = rhs._inventory[i];
	std::cout << YELLOW_F << "Copy Ground assignement operator called" << std::endl;
	return *this;
}

AMateria	*Ground::find(int idx)
{
	AMateria	*ptr;

	if (idx >= 0 && idx < 10 && _inventory[idx])
	{
		ptr = _inventory[idx];
		while (idx < 9)
		{
			_inventory[idx] = _inventory[idx + 1];
			idx++;
		}
		std::cout << "Object " << ptr->getType() << " found on the ground" << std::endl;
		return ptr;
	}
	std::cout << "No object at index " << idx << " on the ground" << std::endl;
	return NULL;
}

void	Ground::fall(AMateria *m)
{
	static int	j;

	std::cout << "Object " << m->getType() << " fell on the ground" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = m;
			return ;
		}
	}
	delete _inventory[j % 10];
	_inventory[j % 10] = m;
	j++;
}
