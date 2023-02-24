/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:22:20 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/24 12:38:09 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include "colors.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	ClapTrap::_name = "_clap_name";
	_name = "";
	std::cout << MAGENTA_F << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << MAGENTA_F << "Name DiamondTrap destructor named " << _name << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	this->ClapTrap::_name = name + "_clap_name";
	this->_name = name;
	std::cout << MAGENTA_F << "Name DiamondTrap constructor named " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &rhs) : ClapTrap(), FragTrap(), ScavTrap()
{
	*this = rhs;
	std::cout << MAGENTA_F << "Copy DiamondTrap constructor named " << _name << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &rhs)
{
	this->_name = rhs._name;
	this->ClapTrap::_name = rhs.ClapTrap::_name;
	this->_hit_points = rhs._hit_points;
	this->_init_hit_points = rhs._init_hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	std::cout << MAGENTA_F << "Copy DiamondTrap assignement operator named " << _name << std::endl;
	return *this;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}
