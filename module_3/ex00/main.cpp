/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:07:20 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/23 14:40:59 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "colors.hpp"

int	main(void)
{
	ClapTrap	paul("Paul");
	ClapTrap	quentin("Quentin");

	std::cout << RED_F << quentin << std::endl;
}
