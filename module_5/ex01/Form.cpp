/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:31:37 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/06 11:13:57 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "colors.hpp"
#include "Bureaucrat.hpp"

// destructor

Form::~Form(void)
{
	std::cout << BLUE_F << "Default Form destructor called" << std::endl;
}

// constructors

Form::Form(void) : _name(""), _signed(false), _grade_to_signed(150), _grade_to_execute(150)
{
	std::cout << BLUE_F << "Default Form constructor called" << std::endl;
}

Form::Form(const std::string name, int grade_to_signed, int grade_to_execute) : _name(name), _signed(false), _grade_to_signed(grade_to_signed), _grade_to_execute(grade_to_execute)
{
	std::cout << BLUE_F << "String and int Form constructor called" << std::endl;
}

Form::Form(const Form &rhs) : _name(rhs._name), _signed(rhs._signed), _grade_to_signed(rhs._grade_to_signed), _grade_to_execute(rhs._grade_to_execute)
{
	std::cout << BLUE_F << "Copy Form constructor called" << std::endl;
}

// operator overloads

Form	&Form::operator=(const Form &rhs)
{
	_signed = rhs._signed;
	std::cout << BLUE_F << "Copy Form assignement operator called" << std::endl;
	return *this;
}

// getters

const std::string	Form::getName(void) const
{
	return _name;
}

unsigned int	Form::getGradeToSigned(void) const
{
	return _grade_to_signed;
}

unsigned int	Form::getGradeToExecute(void) const
{
	return _grade_to_execute;
}

bool	Form::getSigned(void) const
{
	return _signed;
}

std::ostream	&operator<<(std::ostream &o, const Form &rhs)
{
	o << "Form named is " << rhs.getName() << ", required grade is " << rhs.getGradeToExecute() << ", signed grade is " << rhs.getGradeToSigned();
	if (rhs.getSigned())
		o << ", form is signed";
	else
		o << ", form is not signed";
	return o;
}

void	Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _grade_to_execute)
		_signed = true;
	else
		throw GradeTooLowException();
}
