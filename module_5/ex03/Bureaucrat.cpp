/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:39:20 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/01 12:26:18 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "colors.hpp"
#include "AForm.hpp"

// destructor

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED_F << "Default Bureaucrat destructor called" << std::endl;
}

// constructors

Bureaucrat::Bureaucrat(void) : _name(""), _grade(150)
{
	std::cout << RED_F << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
	std::cout << RED_F << "String and int Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &rhs) : _name(rhs._name)
{
	*this = rhs;
	std::cout << RED_F << "Copy Bureaucrat constructor called" << std::endl;
}

// operator overloads

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	_grade = rhs._grade;
	std::cout << RED_F << "Copy Bureaucrat assignement operator called" << std::endl;
	return *this;
}

// getters

const std::string	Bureaucrat::getName(void) const
{
	return _name;
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return _grade;
}

void	Bureaucrat::increment(void)
{
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade -= 1;
}

void	Bureaucrat::decrement(void)
{
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade += 1;
}

void	Bureaucrat::signForm(AForm &f)
{
	try {
		f.beSigned(*this);
		std::cout << _name << " signed " << f.getName() << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cout << _name << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " could not execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

// non member function

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}
