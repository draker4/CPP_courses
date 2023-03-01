/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:26:39 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/01 13:24:22 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// destructor

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << MAGENTA_F << "Default ShrubberyCreationForm destructor called" << std::endl;
}

// constructors

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("shrubbery creation", 145, 137), _target("")
{
	std::cout << MAGENTA_F << "Default ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("shrubbery creation", 145, 137), _target(target)
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
	return *this;
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::FormNotSigned();
	if (executor.getGrade() > this->getGradeRequired())
		throw AForm::GradeTooLowException();
	std::ofstream	file((_target+ std::string("_shrubbery")).c_str(), std::ofstream::out | std::ofstream::trunc);
	if (!file.is_open())
		throw AForm::FileNotOpen();
	file << "writes ASCII trees" << std::endl;
	file.close();
}
