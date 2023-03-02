/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:05:25 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/02 12:57:31 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include "colors.hpp"

// constructors

Conversion::Conversion(void)
{
	std::cout << RED_F << "Default Conversion constructor" << std::endl;
	throw Conversion::WrongArgs();
}

Conversion::Conversion(std::string arg) : _int(0), _char('\0'), _float(0.0f), _double(0.0)
{
	std::cout << RED_F << "String Conversion constructor" << std::endl;
	
	_type = Convert(arg);
	if (!_type.compare("char"))
		_char = arg[0];
	else if (!arg.compare("int"))
		_int = std::stoi(arg);
	else if (!arg.compare("float"))
		_int = std::stof(arg);
	else if (!arg.compare("double"))
		_int = std::stod(arg);
}

Conversion::Conversion(const Conversion &rhs)
{
	*this = rhs;
	std::cout << RED_F << "Copy Conversion constructor" << std::endl;
}

// operator overloads

Conversion	&operator=(const Conversion)
{
	
}

// non member functions

std::string	Convert(const std::string arg)
{
	int	nb_point = 0;

	if (!arg.compare("-inff") || !arg.compare("inff") || !arg.compare("nanf"))
		return "float";
	else if (!arg.compare("-inf") || !arg.compare("inf") || !arg.compare("nan"))
		return "double";
	if (arg[0] == '+' || arg[0] == '-' || std::isdigit(arg[0]))
	{
		if (arg.substr(1).find_first_not_of("0123456789") == std::string::npos)
			return ("int");
		else
		{
			for (int i = 0; i < arg.length(); i++)
			{
				if (i == arg.length() && arg[i] == 'f')
					return "float";
				if (arg[i] == '.')
					nb_point++;
				if ((!std::isdigit(arg[i]) && arg[i] != '.') || nb_point > 1)
					throw Conversion::WrongArgs();
			}
			return "double";
		}
	}
	throw Conversion::WrongArgs();
	return (NULL);
}
