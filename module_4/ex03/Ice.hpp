/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:40:37 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/27 15:12:47 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	private:

	public:

		Ice(void);
		Ice(const Ice &rhs);
		~Ice(void);
		
		Ice	&operator=(const Ice &rhs);

		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif
