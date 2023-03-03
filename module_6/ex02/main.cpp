/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:24:46 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 14:03:02 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "colors.hpp"

int	main(void)
{
  	srand(time(NULL));
	Base	*first = generate();
	Base	*second = generate();
	Base	*third = generate();

	identify(first);
	identify(second);
	identify(third);
	
	std::cout << std::endl;
	
	identify(*first);
	identify(*second);
	identify(*third);
	
	delete first;
	delete second;
	delete third;
}
