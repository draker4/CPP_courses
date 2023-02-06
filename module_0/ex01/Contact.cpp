/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 12:27:44 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/06 14:37:41 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	
}

Contact::~Contact(void)
{
	
}

std::string	Contact::_getString(std::string str) const
{
	std::string	input;
	bool		check = false;

	while (!check)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, input);
		if (std::cin.good() && !input.empty())
			check = true;
		else
			std::cout << "Sorry wrong input." << std::endl;
	}
	return (input);
}

void	Contact::initContact(void)
{
	std::cin.ignore();
	this->_first_name = this->_getString("Enter a first name: ");
	this->_last_name = this->_getString("Enter a last name: ");
	this->_nickname = this->_getString("Enter a nick name: ");
	this->_phone_number = this->_getString("Enter a phone number: ");
	this->_darkest_secret = this->_getString("Enter his darkest secret: ");
}
