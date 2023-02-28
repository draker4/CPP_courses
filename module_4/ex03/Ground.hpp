/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ground.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:50:10 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 12:43:52 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GROUND_HPP
# define GROUND_HPP

# include "AMateria.hpp"

class	Ground
{
	private:

		AMateria	*_inventory[10];
		
	public:

		Ground(void);
		Ground(const Ground &rhs);
		~Ground(void);

		Ground	&operator=(const Ground &rhs);
		
		AMateria	*find(int idx);
		void		fall(AMateria *m);
};

#endif
