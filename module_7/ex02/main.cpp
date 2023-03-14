/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:50:08 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/14 13:45:33 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"
#include "Array.hpp"
#include <cstdlib>

int	main(void)
{
	Array<int> first;
	Array<double> second(10);
	
	std::cout << std::endl;
	std::cout << RESET << YELLOW_B << "size of first array = " << first.size() << RESET << std::endl;
	std::cout << RESET << YELLOW_B << "size of second array = " << second.size() << RESET << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl;
	try {
		second[4] = 12.4;
		std::cout << RESET << RED_B << "fourth of second array = " << second[4] << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "error occured because : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << std::endl;
	try {
		second[0] = 12;
		std::cout << RESET << RED_B << "tenth of second array = " << second[4] << RESET << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "error occured because : " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	Array<double>	copy;
	copy = second;
	std::cout << std::endl;
	try {
		std::cout << RESET << RED_B << "fourteenth of copy array = " << RESET << second[14] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "error occured because : " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }
