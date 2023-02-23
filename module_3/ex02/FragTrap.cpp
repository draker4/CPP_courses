/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:55:24 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/23 17:18:28 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "colors.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_hit_points = 100;
	this->_init_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << RED_F << "Default FragTrap constructor called" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << RED_F << "Default FragTrap destructor named " << _name << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_init_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << RED_F << "Name FragTrap constructor named " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs) : ClapTrap(rhs)
{
	std::cout << RED_F << "Copy FragTrap constructor named " << _name << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &rhs)
{
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_init_hit_points = rhs._init_hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	std::cout << RED_F << "Copy ScavTrap assignement operator named " << _name << std::endl;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << RED_F << _name << " ask for a high fives" << std::endl;
}
