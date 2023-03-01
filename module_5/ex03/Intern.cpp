/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:24:41 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/01 14:50:10 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// destructor

Intern::~Intern(void)
{
	std::cout << CYAN_F << "Default Intern destructor called" << RESET << std::endl;
}

Intern::Intern(void)
{
	std::cout << CYAN_F << "Default Intern constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &rhs)
{
	*this = rhs;
	std::cout << CYAN_F << "Copy Intern constructor called" << RESET << std::endl;
}

// operator overloads

Intern	&Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	std::cout << CYAN_F << "Copy Intern assignement operator called" << RESET << std::endl;
	return *this;
}

// member functions

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string	tab[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	AForm		*form;
	int			i;

	for (i = 0; i < 3; i++)
	{
		if (!tab[i].compare(name))
			break ;
	}
	switch (i)
	{
		case 0:
			form = new RobotomyRequestForm(target);
			break ;
		case 1:
			form = new ShrubberyCreationForm(target);
			break ;
		case 2:
			form = new PresidentialPardonForm(target);
			break ;
		default:
			std::cout << "No form exists with this name" << std::endl;
			return NULL;
	}
	std::cout << "Intern creates " << form->getName() << std::endl;
	return form;
}
