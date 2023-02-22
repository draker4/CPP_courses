/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:22:38 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/22 13:26:01 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "colors.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);;

int main(void)
{
	{
		Point	a;
		Point	b(2, 4.3);
		Point	c(b);
		
		std::cout << std::endl;
		std::cout << YELLOW_B << BLACK_F << "a :" << a << RESET << std::endl;
		std::cout << YELLOW_B << BLACK_F << "b :" << b << RESET << std::endl;
		std::cout << YELLOW_B << BLACK_F << "c :" << c << RESET << std::endl;
	}
	{
		std::cout << std::endl;

		Point	d;
		Point	e;
		Fixed	aa(47.9f);
		Fixed	bb(-4.23f);

		d.setX(aa);
		d.setY(bb);
		e = d;
		std::cout << YELLOW_B << BLACK_F << "d :" << d << RESET << std::endl;
		std::cout << YELLOW_B << BLACK_F << "e :" << e << RESET << std::endl;
	}
	{
		std::cout << std::endl;
		std::cout << YELLOW_B << BLACK_F << "TEST TRIANGLE" << RESET << std::endl;
		std::cout << std::endl;

		Point	a(0, 0);
		Point	b(4, 0);
		Point	c(2, 3);
		Point	d(2, 1);
		
		std::cout << std::endl;
		if (bsp(a, b, c, d))
			std::cout << YELLOW_B << BLACK_F << "Point d in triangle abc" << RESET << std::endl;
		else
			std::cout << YELLOW_B << BLACK_F << "Point d not in triangle abc" << RESET << std::endl;
		std::cout << std::endl; 
	}
	return 0;
}
