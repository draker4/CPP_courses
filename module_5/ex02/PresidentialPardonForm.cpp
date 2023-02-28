/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:26:39 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 11:38:24 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "PresidentialPardonForm.hpp"

// destructor

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << MAGENTA_F << "Default PresidentialPardonForm destructor called" << std::endl;
}

// constructors

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5), _target("")
{
	std::cout << MAGENTA_F << "Default PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << MAGENTA_F << "String PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &rhs) : AForm(rhs), _target(rhs._target)
{
	std::cout << MAGENTA_F << "Copy PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	_target = rhs._target;
	std::cout << MAGENTA_F << "Copy PresidentialPardonForm assignement operator called" << std::endl;
}
