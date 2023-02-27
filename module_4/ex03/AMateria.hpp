/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:19:07 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/27 14:10:24 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:
	
		AMateria(void);

		std::string	_type;

	public:
	
		AMateria(std::string const &type);
		AMateria(const AMateria &rhs);
		virtual ~AMateria(void);
		
		AMateria	&operator=(const AMateria &rhs);

		std::string const 	&getType() const;
		
		virtual	AMateria	*clone() const = 0;
		virtual void		use(ICharacter &target);
		
};

#endif
