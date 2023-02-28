/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:07:55 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 11:05:02 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Bureaucrat.hpp"
#include "Form.hpp"

void	testLowForm(void)
{
	Form f1("first", 12, 34);
	Bureaucrat	bapt("Bapt", 100);
	
	std::cout << RESET << f1 << std::endl;
	bapt.signForm(f1);
	std::cout << RESET << f1 << std::endl;
}

void	testOkForm(void)
{
	Form f1("first", 12, 34);
	Bureaucrat	bapt("Bapt", 30);
	
	std::cout << RESET << f1 << std::endl;
	bapt.signForm(f1);
	std::cout << RESET << f1 << std::endl;
}

int	main(void)
{
	std::cout << WHITE_B << BLACK_F << "Test Form" << RESET << std::endl;
	std::cout << std::endl;
	
	testLowForm();
	std::cout << std::endl;
	testOkForm();
	std::cout << std::endl;
}
