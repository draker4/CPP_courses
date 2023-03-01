/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:26:39 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 17:41:07 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

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

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeRequired())
		throw AForm::GradeTooLowException();
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" ,, std::endl;
}
