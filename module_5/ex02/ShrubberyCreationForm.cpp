/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:26:39 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 11:33:56 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "ShrubberyCreationForm.hpp"

// destructor

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << MAGENTA_F << "Default ShrubberyCreationForm destructor called" << std::endl;
}

// constructors

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), _target("")
{
	std::cout << MAGENTA_F << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << MAGENTA_F << "String ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &rhs) : AForm(rhs), _target(rhs._target)
{
	std::cout << MAGENTA_F << "Copy ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	_target = rhs._target;
	std::cout << MAGENTA_F << "Copy ShrubberyCreationForm assignement operator called" << std::endl;
}
