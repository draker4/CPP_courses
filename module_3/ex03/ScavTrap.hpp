/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:55:33 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/23 17:37:39 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:

		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &rhs);
		~ScavTrap(void);
		
		ScavTrap	&operator=(const ScavTrap &rhs);
		
		void		guardGate(void);
		void		attack(const std::string &target);

	protected:
	
		ScavTrap(void);
};

#endif
