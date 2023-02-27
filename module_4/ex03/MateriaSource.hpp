/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 18:52:58 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/27 19:18:23 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	private :
	
		AMateria		*_inventory[4];

	public:
		
		MateriaSource(void);
		MateriaSource(const MateriaSource &rhs);
		~MateriaSource(void);
	
		MateriaSource	&operator=(const MateriaSource &rhs);

		void 			learnMateria(AMateria*);
		AMateria* 		createMateria(std::string const & type);

};

#endif
