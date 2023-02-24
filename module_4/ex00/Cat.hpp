/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:44:48 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/24 14:47:22 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:

	public:

		Cat(void);
		Cat(const Cat &rhs);
		~Cat(void);

		Cat &operator=(const Cat &rhs);
		
		void	makeSound(void) const;
};

#endif
