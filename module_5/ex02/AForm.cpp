/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:31:37 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 11:21:04 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "colors.hpp"
#include "Bureaucrat.hpp"

// destructor

AForm::~AForm(void)
{
	std::cout << BLUE_F << "Default AForm destructor called" << std::endl;
}

// constructors

AForm::AForm(void) : _name(""), _signed(false), _grade_to_signed(150), _grade_required(150)
{
	std::cout << BLUE_F << "Default AForm constructor called" << std::endl;
}

AForm::AForm(const std::string name, int grade_to_signed, int _grade_required) : _name(name), _signed(false), _grade_to_signed(grade_to_signed), _grade_required(_grade_required)
{
	std::cout << BLUE_F << "String and int AForm constructor called" << std::endl;
}

AForm::AForm(const AForm &rhs) : _name(rhs._name), _signed(rhs._signed), _grade_to_signed(rhs._grade_to_signed), _grade_required(rhs._grade_required)
{
	std::cout << BLUE_F << "Copy AForm constructor called" << std::endl;
}

// operator overloads

AForm	&AForm::operator=(const AForm &rhs)
{
	_signed = rhs._signed;
	std::cout << BLUE_F << "Copy AForm assignement operator called" << std::endl;
	return *this;
}

// getters

const std::string	AForm::getName(void) const
{
	return _name;
}

unsigned int	AForm::getGradeToSigned(void) const
{
	return _grade_to_signed;
}

unsigned int	AForm::getGradeRequired(void) const
{
	return _grade_required;
}

bool	AForm::getSigned(void) const
{
	return _signed;
}

std::ostream	&operator<<(std::ostream &o, const AForm &rhs)
{
	o << "Form named is " << rhs.getName() << ", required grade is " << rhs.getGradeRequired() << ", signed grade is " << rhs.getGradeToSigned();
	if (rhs.getSigned())
		o << ", form is signed";
	else
		o << ", form is not signed";
	return o;
}

void	AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= _grade_required)
		_signed = true;
	else
		throw GradeTooLowException();
}
