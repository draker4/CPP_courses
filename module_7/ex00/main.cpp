/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:25:48 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/14 13:11:49 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "whatever.hpp"

#include <iostream>

int	main(void)
{
	{
		std::cout << CYAN_B << "My first test" << RESET << std::endl;
		std::cout << std::endl;
		
		int		a = 3;
		int		b = 78;

		float	c = -12.1f;
		float	d = -12.05f;
		
		std::cout << "min between 3 and 78 = " << min(a, b) << std::endl;
		std::cout << "max between -12.1 and -12.05 = " << max(c, d) << std::endl;
	}
	
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << CYAN_B << "Main test" << RESET << std::endl;
		std::cout << std::endl;
	
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	
	return 0;
}
