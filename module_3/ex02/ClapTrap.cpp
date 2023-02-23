/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:32:37 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/23 16:53:54 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.hpp"

ClapTrap::ClapTrap(void) : _name(""), _hit_points(10), _init_hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << BLUE_F << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10),  _init_hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << BLUE_F << "Name ClapTrap constructor named " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs) : _name(rhs._name), _hit_points(rhs._hit_points),  _init_hit_points(rhs._init_hit_points), _energy_points(rhs._energy_points), _attack_damage(rhs._attack_damage)
{
	std::cout << BLUE_F << "Copy ClapTrap constructor named " << _name << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << BLUE_F << "ClapTrap destructor named " << _name << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &rhs)
{
	_name = rhs._name;
	_hit_points = rhs._hit_points;
	_init_hit_points = rhs._init_hit_points;
	_energy_points = rhs._energy_points;
	_attack_damage = rhs._attack_damage;
	std::cout << BLUE_F << "Copy ClapTrap assignement operator named " << _name << std::endl;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, const ClapTrap &rhs)
{
	o << "name = " << rhs.getName() << ", hit points = " << rhs.getHitPoints() << ", energy points = " << rhs.getEnergyPoints() << ", attack damage = " << rhs.getAttackDamage();
	return o;
}

std::string	ClapTrap::getName(void) const
{
	return _name;
}

int	ClapTrap::getHitPoints(void) const
{
	return _hit_points;
}

int	ClapTrap::getEnergyPoints(void) const
{
	return _energy_points;
}

int	ClapTrap::getAttackDamage(void) const
{
	return _attack_damage;
}

void	ClapTrap::attack(const std::string &target)
{
	if (_energy_points <= 0)
	{
		std::cout << GREEN_F << "ClapTrap " << _name << " cannot attack because he has no energy point!" << std::endl;
		return ;
	}
	_energy_points--;
	std::cout << GREEN_F << "ClapTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	_hit_points -= amount;
	if (_hit_points <= 0)
		std::cout << GREEN_F << "ClapTrap " << _name << " is dead" << std::endl;
	std::cout << GREEN_F << "ClapTrap " << _name << " taked " << amount << " points of damage, he has now " << _hit_points << " points of life" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points <= 0)
	{
		std::cout << GREEN_F << "ClapTrap " << _name << " cannot repair himself because he has no energy point!" << std::endl;
		return ;
	}
	if (_hit_points >= _init_hit_points)
	{
		std::cout << GREEN_F << "ClapTrap " << _name << " cannot repair himself because he has all his life" << std::endl;
		return ;
	}
	_energy_points--;
	_hit_points += amount;
	if (_hit_points > _init_hit_points)
		_hit_points = _init_hit_points;
	std::cout << GREEN_F << "ClapTrap " << _name << " repaired himself and has now " << _hit_points << " points of life" << std::endl;
}
