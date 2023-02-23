/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:07:41 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/23 16:52:12 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_H
# define CLAPTRAP_H

# include <iostream>

class ClapTrap
{
	public:
	
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &rhs);
		~ClapTrap();
		
		ClapTrap	&operator=(const ClapTrap &rhs);
		
		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);

	protected:
		ClapTrap(void);

		std::string	_name;
		int			_hit_points;
		int			_init_hit_points;
		int			_energy_points;
		int			_attack_damage;
	
};

std::ostream	&operator<<(std::ostream &o, const ClapTrap &rhs);

#endif
