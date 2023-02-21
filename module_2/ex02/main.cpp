/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:22:38 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/21 18:38:38 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "colors.hpp"

int main(void)
{
	{
		std::cout << YELLOW_F << BOLD << "Comparison operators" << RESET << std::endl;
		
		Fixed	a;
		Fixed	b(45);
		Fixed	c(45.0f);

		a = Fixed(64);

		std::cout << BLUE_F << "a > b :" << (a > b) << std::endl;
		std::cout << BLUE_F << "a <= b :" << (a < b) << std::endl;
		std::cout << BLUE_F << "a != b :" << (a != b) << std::endl;
		std::cout << BLUE_F << "b == c :" << (b == c) << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << YELLOW_F << BOLD << "Arithmetic operators" << RESET << std::endl;

		Fixed a(24);
		Fixed b(12);
		Fixed c(24.2f);
		Fixed d = a + b;

		std::cout << MAGENTA_F << "a + b :" << (a + b) << std::endl;
		std::cout << MAGENTA_F << "d :" << d << std::endl;
		std::cout << MAGENTA_F << "c - b :" << (c - b) << std::endl;
		std::cout << MAGENTA_F << "a / b :" << (a / b) << std::endl;
	}

	{
		std::cout << std::endl;
		std::cout << YELLOW_F << BOLD << "Increment operators" << RESET << std::endl;

		Fixed 		a;
		Fixed const b(Fixed(5.05f) * Fixed(2));

		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	return 0;
}
