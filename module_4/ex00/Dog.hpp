/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:44:48 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/24 14:36:15 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class	Dog : public Animal
{
	private :

	public :
	
		Dog(void);
		Dog(const Dog &rhs);
		~Dog(void);
		
		Dog	&operator=(const Dog &rhs);
		
		void	makeSound(void) const;
};

#endif
