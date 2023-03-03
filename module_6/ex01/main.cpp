/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:37:51 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 12:56:29 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Data.hpp"

int	main(void)
{
	Data	data;
	
	data.i_test = 10;
	data.s_test = "salut";
	
	Data	*ptr_data = &data;

	std::cout << "int =" << ptr_data->i_test << std::endl;
	std::cout << "string =" << ptr_data->s_test << std::endl;
	std::cout << "address =" << ptr_data << std::endl;
	std::cout << std::endl;
	
	uintptr_t	ptr;
	ptr = serialize(ptr_data);
	
	Data	*return_ptr;
	return_ptr = deserialize(ptr);
	
	std::cout << "int =" << return_ptr->i_test << std::endl;
	std::cout << "string =" << return_ptr->s_test << std::endl;
	std::cout << "address =" << return_ptr << std::endl;
	
	return 0;
}
