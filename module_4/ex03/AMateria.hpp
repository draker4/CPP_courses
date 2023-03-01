/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:19:07 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/01 11:30:49 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class ICharacter;

class AMateria
{
	protected:
	
		AMateria(void);

		std::string	_type;
		bool		_equip;

	public:
	
		AMateria(std::string const &type);
		AMateria(const AMateria &rhs);
		virtual ~AMateria(void);
		
		AMateria	&operator=(const AMateria &rhs);

		std::string const 	&getType() const;
		bool				getEquip() const;
		void				setEquip(bool equip);
		
		virtual	AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
		
};

#endif
