/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:22:03 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 16:49:16 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
	public:
	
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &rhs);
		~DiamondTrap(void);

		DiamondTrap	&operator=(const DiamondTrap &rhs);
		void		attack(const std::string &target);
		void		whoAmI(void) const;
	
	private:
	
		DiamondTrap(void);
		
		std::string	_name;
};

#endif
