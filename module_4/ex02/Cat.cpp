/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:44:36 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/24 15:53:50 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "colors.hpp"

// constructors - destrcutor

Cat::~Cat(void)
{
	delete (_brain);
	std::cout << YELLOW_F << "Default Cat destructor called" << RESET << std::endl;
}

Cat::Cat(void)
{
	_type = "Cat";
	std::cout << YELLOW_F << "Default Cat constructor called" << std::endl;
	_brain = new Brain();
}

Cat::Cat(const Cat &rhs) : AAnimal()
{
	*this = rhs;
	std::cout << YELLOW_F << "Copy Cat constructor called" << std::endl;
}

// operator

Cat &Cat::operator=(const Cat &rhs)
{
	_type = rhs._type;
	_brain = rhs._brain;
	std::cout << YELLOW_F << "Copy assignement Cat operator called" << std::endl;
	return *this;
}

// functions

void	Cat::makeSound(void) const
{
	std::cout << YELLOW_F << "Cat says MIAOU" << std::endl;
}
