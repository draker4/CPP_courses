/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:55:24 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/23 17:11:49 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "colors.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_hit_points = 100;
	this->_init_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << YELLOW_F << "Default ScavTrap constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << YELLOW_F << "Default ScavTrap destructor named " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_init_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << YELLOW_F << "Name ScavTrap constructor named " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &rhs) : ClapTrap(rhs)
{
	std::cout << YELLOW_F << "Copy ScavTrap constructor named " << _name << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &rhs)
{
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_init_hit_points = rhs._init_hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	std::cout << YELLOW_F << "Copy ScavTrap assignement operator named " << _name << std::endl;
	return *this;
}

void	ScavTrap::guardGate(void)
{
	std::cout << YELLOW_F << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (_energy_points <= 0)
	{
		std::cout << YELLOW_F << "ScavTrap " << _name << " cannot attack because he has no energy point!" << std::endl;
		return ;
	}
	_energy_points--;
	std::cout << YELLOW_F << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack_damage << " points of damage" << std::endl;
}
