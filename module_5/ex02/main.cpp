/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:07:55 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 14:03:24 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	testOkSigned(void)
{
	AForm		*f1 = new PresidentialPardonForm("haha");
	Bureaucrat	bapt("Bapt", 2);
	
	std::cout << RESET << *f1 << std::endl;
	bapt.signForm(*f1);
	std::cout << RESET << *f1 << std::endl;
	delete f1;
}

void	testOkExecution(void)
{
	AForm	*f1 = new PresidentialPardonForm("form1");
	AForm	*f2 = new ShrubberyCreationForm("form2");
	AForm	*f3 = new RobotomyRequestForm("form3");

	std::cout << RESET << *f1 << std::endl;
	std::cout << RESET << *f2 << std::endl;
	std::cout << RESET << *f3 << std::endl;
	
	Bureaucrat	me("Joseph", 1);
	me.signForm(*f1);
	me.signForm(*f2);
	me.executeForm(*f1);
	me.executeForm(*f2);
	me.executeForm(*f3);

	delete f1;
	delete f2;
	delete f3;
}

int	main(void)
{
  	srand(time(NULL));
	std::cout << WHITE_B << BLACK_F << "Test Form" << RESET << std::endl;
	std::cout << std::endl;
	
	testOkSigned();
	std::cout << std::endl;
	testOkExecution();
	std::cout << std::endl;
}
