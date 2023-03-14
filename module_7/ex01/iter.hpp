/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:34:57 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/14 13:13:16 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *array, int size, void (*funct)(const T&))
{
	for (int i = 0; i < size; i++)
		(*funct)(array[i]);
}

template <typename T>
void	func1(T const &x)
{
	std::cout << MAGENTA_B << x << RESET << std::endl;
}

#endif
