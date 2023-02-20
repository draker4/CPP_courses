/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:24:15 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/20 12:17:47 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str="HI THIS IS BRAIN";
	std::string	*ptr_str = &str;
	std::string	&ref_str = str;

	std::cout << "Adress of str is " << &str << std::endl;
	std::cout << "Adress of ptr_str is " << ptr_str << std::endl;
	std::cout << "Adress of ref_ptr is " << &ref_str << std::endl;

	std::cout << std::endl;
	std::cout << "Value of str is " << str << std::endl;
	std::cout << "Value of ptr_str is " << *ptr_str << std::endl;
	std::cout << "Value of ref_str is " << ref_str << std::endl;
}
