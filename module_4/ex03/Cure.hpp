/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:40:37 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/27 15:12:41 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cure_HPP
# define Cure_HPP

# include "AMateria.hpp"

class Cure : public AMateria
{
	private:

	public:

		Cure(void);
		Cure(const Cure &rhs);
		~Cure(void);
		
		Cure	&operator=(const Cure &rhs);
		
		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif
