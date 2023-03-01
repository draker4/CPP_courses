/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:26:39 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/01 13:24:01 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

// destructor

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << MAGENTA_F << "Default RobotomyRequestForm destructor called" << std::endl;
}

// constructors

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("robotomy request", 72, 45), _target("")
{
	std::cout << MAGENTA_F << "Default RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("robotomy request", 72, 45), _target(target)
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
	return *this;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeRequired())
		throw AForm::GradeTooLowException();
	std::cout << "Some drilling noises..." << std::endl;
	if (rand() % 2)
		std::cout << MAGENTA_F << _target << " has been robotomized successfully" << std::endl;
	else
		std::cout << MAGENTA_F << "the robotomy of " << _target << " has failed" << std::endl;
}
