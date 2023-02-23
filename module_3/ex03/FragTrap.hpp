/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:55:33 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/23 17:37:34 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:

		FragTrap(std::string name);
		FragTrap(const FragTrap &rhs);
		~FragTrap(void);
		
		FragTrap	&operator=(const FragTrap &rhs);

		void		highFivesGuys(void);

	protected:
	
		FragTrap(void);
};

#endif
