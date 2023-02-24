/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:35:09 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/24 15:49:54 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
	
		std::string	_type;
	
	public:
	
		AAnimal(void);
		AAnimal(const AAnimal &rhs);
		virtual ~AAnimal(void);

		AAnimal			&operator=(const AAnimal &rhs);
		
		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;

};

#endif
