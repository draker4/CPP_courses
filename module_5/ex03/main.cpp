/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:07:55 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/06 11:23:46 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <cstdlib>

void	testIntern(void)
{
	AForm		*f1;
	Intern		you;
	Bureaucrat	me("Haha", 1);
	
	f1 = you.makeForm("presidential pardon", "home");
	std::cout << RESET << *f1 << std::endl;
	me.signForm(*f1);
	std::cout << RESET << *f1 << std::endl;
	me.executeForm(*f1);
	delete f1;
}

int	main(void)
{
  	srand(time(NULL));
	std::cout << WHITE_B << BLACK_F << "Test Form" << RESET << std::endl;
	std::cout << std::endl;
	
	testIntern();
	std::cout << std::endl;
}
