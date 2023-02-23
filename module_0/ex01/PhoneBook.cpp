/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:40:09 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/20 16:48:53 by bperriol         ###   ########lyon.fr   */
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

void PhoneBook::begin(void)
{
	std::cout << std::endl
			  << std::endl;
	std::cout << "Welcome in your favorite PhoneBook!" << std::endl;
	std::cout << "Please enter one of the following commands:" << std::endl;
	std::cout << "Enter 'ADD' to save a contact." << std::endl;
	std::cout << "Enter 'SEARCH' to display all contacts." << std::endl;
	std::cout << "Enter 'EXIT' to quit the PhoneBook" << std::endl;
	std::cout << std::endl;
	_nb_contacts = 0;
}

void PhoneBook::add(void)
{
	static int index;
	Contact contact;

	contact.initContact();
	contact.setIndex(index % 8);
	_contact[index % 8] = contact;
	index++;
	if (_nb_contacts < 8)
		_nb_contacts++;
}

int PhoneBook::_read_index(void) const
{
	bool check = false;
	int index;

	while (!check)
	{
		std::cout << "Enter the contact index :" << std::flush;
		std::cin >> index;
		if (std::cin.good() && index >= 0 && index < _nb_contacts)
			check = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Please enter an index between 0 and " << _nb_contacts - 1 << "!" << std::endl;
		}
	}
	return (index);
}

void PhoneBook::search(void) const
{
	int i;

	i = -1;
	if (_nb_contacts == 0)
	{
		std::cout << "No contact yet!" << std::endl;
		return;
	}
	while (++i < _nb_contacts)
		_contact[i].print_name(i);
	i = _read_index();
	_contact[i].print_all(i);
}
