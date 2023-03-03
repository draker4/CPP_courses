/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:40:55 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 12:54:58 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "colors.hpp"

uintptr_t serialize(Data* ptr)
{
	uintptr_t	uintptr;

	uintptr = reinterpret_cast<uintptr_t>(ptr);
	return uintptr;
}

Data* deserialize(uintptr_t raw)
{
	Data	*ptr_data;

	ptr_data = reinterpret_cast<Data *>(raw);
	return ptr_data;
}
