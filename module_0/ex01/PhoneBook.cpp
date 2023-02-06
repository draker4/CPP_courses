/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:40:09 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/06 14:22:37 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	
}

PhoneBook::~PhoneBook(void)
{
	
}

void	PhoneBook::begin(void)
{
	std::cout << "Welcome in your favorite PhoneBook!" << std::endl;
	std::cout << "Please enter one of the following commands:" << std::endl;
	std::cout << "Enter 'ADD' to save a contact." << std::endl;
	std::cout << "Enter 'SEARCH' to display all contacts." << std::endl;
	std::cout << "Enter 'EXIT' to quit the PhoneBook" << std::endl;
	std::cout << std::endl;
}

void	PhoneBook::add(void)
{
	static int	index;
	Contact		contact;

	contact.initContact();
	this->contact[index % 8] = contact;
	index++;
}
