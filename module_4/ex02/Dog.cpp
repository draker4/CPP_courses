/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:44:36 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/24 15:54:14 by bperriol         ###   ########lyon.fr   */
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
	std::cout << BLUE_F << "Default Dog constructor called" << std::endl;
	_brain = new Brain();
}

Dog::Dog(const Dog &rhs) : AAnimal()
{
	*this = rhs;
	std::cout << BLUE_F << "Copy Dog constructor called" << std::endl;
}

// operator

Dog	&Dog::operator=(const Dog &rhs)
{
	_type = rhs._type;
	_brain = rhs._brain;
	std::cout << BLUE_F << "Copy assignement Dog operator called" << std::endl;
	return *this;
}

// functions

void	Dog::makeSound(void) const
{
	std::cout << BLUE_F << "Dog barks" << std::endl;
}
