/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:08:43 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/01 11:32:17 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "colors.hpp"

Ground Character::_ground = Ground();

// destructors - constructors

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	std::cout << YELLOW_F << "Default Character destructor called" << std::endl;
}

Character::Character(void) : _name("")
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << YELLOW_F << "Default Character constructor called" << std::endl;
}

Character::Character(const std::string &name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	std::cout << YELLOW_F << "String Character constructor called" << std::endl;
}

Character::Character(const Character &rhs)
{
	*this = rhs;
	std::cout << YELLOW_F << "Copy Character constructor called" << std::endl;
}

// operator overloads

Character	&Character::operator=(const Character &rhs)
{
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
	for (int i = 0; i < 4; i++)
	{
		if (rhs._inventory[i])
			_inventory[i] = rhs._inventory[i]->clone();
	}
	_name = rhs._name;
	std::cout << YELLOW_F << "Copy Character assignement operator called" << std::endl;
	return (*this);
}

// getter - setter

std::string const	&Character::getName(void) const
{
	return _name;
}

// member functions

void	Character::equip(AMateria *m)
{
	if (m->getEquip())
	{
		std::cout << YELLOW_F << "Object " << m->getType() << " is already equipped" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			m->setEquip(true);
			_inventory[i] = m;
			std::cout << YELLOW_F << "Character " << _name << " equips " << m->getType() << std::endl;
			return ;
		}
	}
	std::cout << YELLOW_F << "Character " << _name << " cannot equip " << m->getType() << " because his inventory is full"<< std::endl;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx] != NULL)
	{
		std::cout << YELLOW_F << "Character " << _name << " unequipped " << _inventory[idx]->getType() << std::endl;
		_ground.fall(_inventory[idx]);
		_inventory[idx]->setEquip(false);
		_inventory[idx] = NULL;
		return ;
	}
	std::cout << YELLOW_F << "Character " << _name << " doesn't have an equipment in slot " << idx << std::endl;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3 && _inventory[idx] != NULL)
	{
		_inventory[idx]->use(target);
		delete(_inventory[idx]);
		_inventory[idx] = NULL;
		return ;
	}
	std::cout << YELLOW_F << "Character " << _name << " doesn't have an equipment in " << idx << " slot" << std::endl;
}

void	Character::find(int idx)
{
	AMateria	*ptr;

	ptr = _ground.Ground::find(idx);
	if (ptr)
	{
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i] == NULL)
			{
				_inventory[i] = ptr;
				_inventory[i]->setEquip(true);
				std::cout << YELLOW_F << "Character " << _name << " equips " << ptr->getType() << std::endl;
				return ;
			}
		}
		std::cout << YELLOW_F << "Character " << _name << " cannot equip " << ptr->getType() << " because his inventory is full"<< std::endl;
		_ground.fall(ptr);
	}
}
