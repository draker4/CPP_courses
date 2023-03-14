/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:34:13 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/14 13:13:29 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "iter.hpp"

int	main(void)
{
	int	array1[] = {1, 23, -56};
	std::string	array2[] = {"salut", "haha", "la ?"};
	
	iter(array1, 3, &func1);
	std::cout << std::endl;
	iter(array2, 3, &func1);
}
