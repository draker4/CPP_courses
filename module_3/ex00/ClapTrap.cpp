/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:32:37 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/23 14:49:46 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _attack(0)
{
	std::cout << BLUE_F << "Default ClapTrap constructor named " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs) : _name(rhs._name), _hit(rhs._hit), _energy(rhs._energy), _attack(rhs._attack)
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
	_hit = rhs._hit;
	_energy = rhs._energy;
	_attack = rhs._attack;
	return *this;
}

std::ostream	&operator<<(std::ostream &o, const ClapTrap &rhs)
{
	o << "name = " << rhs.getName() << ", hit = " << rhs.getHit() << ", energy = " << rhs.getEnergy() << ", attack = " << rhs.getAttack();
	return o;
}

std::string	ClapTrap::getName(void) const
{
	return _name;
}

int	ClapTrap::getHit(void) const
{
	return _hit;
}

int	ClapTrap::getEnergy(void) const
{
	return _energy;
}

int	ClapTrap::getAttack(void) const
{
	return _attack;
}

