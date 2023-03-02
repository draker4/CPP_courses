/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:35:09 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/02 14:28:00 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
	
		std::string	_type;
	
	public:
	
		Animal(void);
		Animal(const Animal &rhs);
		virtual ~Animal(void);

		Animal			&operator=(const Animal &rhs);
		
		std::string		getType(void) const;
		virtual void	makeSound(void) const;

};

#endif
