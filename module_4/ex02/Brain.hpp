/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:22:16 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/24 15:43:02 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
	
		std::string	_ideas[100];

	public:
	
		Brain(void);
		Brain(const Brain &rhs);
		~Brain(void);

		Brain	&operator=(const Brain &rhs);

};

#endif
