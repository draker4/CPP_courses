/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:07:55 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 10:29:27 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Bureaucrat.hpp"

void	testCreateBureaucrat(void)
{
	try {
		Bureaucrat bapt("Bapt", 12);
		
		std::cout << RESET << bapt << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}

void	testTooHighBureaucrat(void)
{
	try {
		Bureaucrat bapt("Bapt", 2);
		Bureaucrat bapt2(bapt);
		
		std::cout << RESET << bapt2 << std::endl;
		bapt2.increment();
		std::cout << RESET << bapt2 << std::endl;
		bapt2.increment();
		std::cout << RESET << bapt2 << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << WHITE_B << BLACK_F << "Test Bureaucrat" << RESET << std::endl;
	std::cout << std::endl;
	
	testCreateBureaucrat();
	std::cout << std::endl;
	testTooHighBureaucrat();
	std::cout << std::endl;
}
