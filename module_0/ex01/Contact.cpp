/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:27:44 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/08 14:41:39 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <cstdlib>

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

std::string Contact::_getString(std::string str) const
{
	std::string input;
	bool check = false;

	while (!check)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(1);
		if (std::cin.good() && !input.empty())
			check = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong input sorry!" << std::endl;
		}
	}
	return (input);
}

void Contact::initContact(void)
{
	_first_name = _getString("Enter a first name: ");
	_last_name = _getString("Enter a last name: ");
	_nickname = _getString("Enter a nick name: ");
	_phone_number = _getString("Enter a phone number: ");
	_darkest_secret = _getString("Enter his darkest secret: ");
}

void Contact::setIndex(int index)
{
	_index = index;
}

void Contact::print_name(int index) const
{
	std::cout << std::setw(10) << index << "|" << std::flush;
	std::cout << std::setw(10) << (_first_name.length() > 9 ? _first_name.substr(0, 9) + "." : _first_name) << "|" << std::flush;
	std::cout << std::setw(10) << (_last_name.length() > 9 ? _last_name.substr(0, 9) + "." : _last_name) << "|" << std::flush;
	std::cout << std::setw(10) << (_nickname.length() > 9 ? _nickname.substr(0, 9) + "." : _nickname) << std::endl;
}

void Contact::print_all(int index) const
{
	std::cout << "Index: " << index << std::endl;
	std::cout << "First name: " << _first_name << std::endl;
	std::cout << "Last name: " << _last_name << std::endl;
	std::cout << "Nick name: " << _nickname << std::endl;
	std::cout << "Phone number: " << _phone_number << std::endl;
	std::cout << "Darkest secret: " << _darkest_secret << std::endl;
	std::cin.ignore();
}
