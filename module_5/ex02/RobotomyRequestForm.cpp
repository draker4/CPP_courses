/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:26:39 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 11:36:54 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "RobotomyRequestForm.hpp"

// destructor

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << MAGENTA_F << "Default RobotomyRequestForm destructor called" << std::endl;
}

// constructors

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("")
{
	std::cout << MAGENTA_F << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << MAGENTA_F << "String RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &rhs) : AForm(rhs), _target(rhs._target)
{
	std::cout << MAGENTA_F << "Copy RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	_target = rhs._target;
	std::cout << MAGENTA_F << "Copy RobotomyRequestForm assignement operator called" << std::endl;
}
