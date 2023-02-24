/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:22:03 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/24 15:42:33 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "colors.hpp"

// constructors - destructor

Brain::~Brain(void)
{
	std::cout << RED_F << "Default Brain destructor called" << RESET << std::endl;
}

Brain::Brain(void)
{
	std::cout << RED_F << "Default Brain constructor called" << RESET << std::endl;
}

Brain::Brain(const Brain &rhs)
{
	*this = rhs;
	std::cout << RED_F << "Copy Brain constructor called" << RESET << std::endl;
}

Brain	&Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < 100; i++)
		_ideas[i] = rhs._ideas[i];
	std::cout << RED_F << "Copy Brain assignement operator called" << RESET << std::endl;
	return *this;
}
