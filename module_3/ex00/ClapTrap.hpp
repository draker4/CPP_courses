/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:07:41 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/23 14:49:27 by bperriol         ###   ########lyon.fr   */
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
		int			getHit(void) const;
		int			getEnergy(void) const;
		int			getAttack(void) const;

	private:
		std::string	_name;
		int			_hit;
		int			_energy;
		int			_attack;
};

std::ostream	&operator<<(std::ostream &o, const ClapTrap &rhs);

#endif
