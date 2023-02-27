/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:43:16 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/27 21:15:16 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	private:
	
		Character(void);
	
		AMateria			*_inventory[4];
		std::string			_name;
		AMateria			*_ground;

	public:
	
		Character(const std::string &name);
		Character(const Character &rhs);
		~Character(void);

		Character			&operator=(const Character &rhs);
		
		std::string const 	&getName(void) const;
		void 				equip(AMateria* m);
		void 				unequip(int idx);
		void 				use(int idx, ICharacter& target);

};

#endif
