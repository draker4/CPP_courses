/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:44:36 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/02 14:32:46 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "colors.hpp"

// constructors - destrcutor

Dog::~Dog(void)
{
	delete (_brain);
	std::cout << BLUE_F << "Default Dog destructor called" << RESET << std::endl;
}

Dog::Dog(void)
{
	_type = "Dog";
	_brain = new Brain();
	std::cout << BLUE_F << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &rhs) : Animal(rhs)
{
	_brain = new Brain(*rhs._brain);
	*this = rhs;
	std::cout << BLUE_F << "Copy Dog constructor called" << std::endl;
}

// operator

Dog	&Dog::operator=(const Dog &rhs)
{
	_type = rhs._type;
	*_brain = *rhs._brain;
	std::cout << BLUE_F << "Copy assignement Dog operator called" << std::endl;
	return *this;
}

// functions

void	Dog::makeSound(void) const
{
	std::cout << BLUE_F << "Dog barks" << std::endl;
}
