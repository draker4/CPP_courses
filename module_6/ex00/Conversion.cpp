/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:05:25 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/02 18:05:30 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Conversion.hpp"
#include "colors.hpp"

// destructor

Conversion::~Conversion(void)
{
	std::cout << RED_F << "Default Conversion destructor" << RESET << std::endl;
}

// constructors

Conversion::Conversion(void): _arg(""), _int(0), _char('\0'), _float(0.0f), _double(0.0)
{
	std::cout << RED_F << "Default Conversion constructor" << std::endl;
}

Conversion::Conversion(std::string arg) : _arg(arg), _int(0), _char('\0'), _float(0.0f), _double(0.0)
{
	Convert(arg);
	std::cout << RED_F << "String Conversion constructor" << std::endl;
}

Conversion::Conversion(const Conversion &rhs)
{
	*this = rhs;
	std::cout << RED_F << "Copy Conversion constructor" << std::endl;
}

// operator overloads

Conversion	&Conversion::operator=(const Conversion &rhs)
{
	_arg = rhs._arg;
	_int = rhs._int;
	_char = rhs._char;
	_float = rhs._float;
	_double = rhs._double;
	std::cout << RED_F << "Copy Conversion assignement operator" << std::endl;
	return *this;
}

// member functions

void	Conversion::Convert(const std::string arg)
{
	int	nb_point = 0;

	if (!arg.compare("-inff") || !arg.compare("inff") || !arg.compare("nanf"))
	{
		_inf = true;
		return ;
	}
	else if (!arg.compare("-inf") || !arg.compare("inf") || !arg.compare("nan"))
	{
		_inff = true;
		return ;
	}
	if (arg[0] == '+' || arg[0] == '-' || std::isdigit(arg[0]))
	{
		if (!arg[1])
			return arg_char(arg);
		else if (arg.substr(1).find_first_not_of("0123456789") == std::string::npos)
			return arg_int(arg);
		else
		{
			for (size_t i = 1; i < arg.length(); i++)
			{
				if (i == arg.length() - 1 && arg[i] == 'f')
					return arg_float(arg);
				if (arg[i] == '.')
					nb_point++;
				if ((!std::isdigit(arg[i]) && arg[i] != '.') || nb_point > 1)
					throw WrongArgs();
			}
			return arg_double(arg);
		}
	}
	if (arg.length() == 1)
		return arg_char(arg);
	throw WrongArgs();
}

void	Conversion::arg_float(std::string arg)
{
	errno = 0;
	double	d = strtod(arg.c_str(), NULL);
	
	if (errno == ERANGE || d < FLT_MIN || d > FLT_MAX)
		throw WrongArgs();
	_float = static_cast<float>(d);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);
	_char = static_cast<char>(_float);
}

void	Conversion::arg_int(std::string arg)
{
	long int	li = strtol(arg.c_str(), NULL, 10);

	if (errno == ERANGE || li > INT_MAX || li < INT_MIN)
		return arg_double(arg);
	_int = static_cast<int>(li);
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
	_char = static_cast<char>(_int);
}

void	Conversion::arg_char(std::string arg)
{
	_char = arg[0];
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
	_int = static_cast<int>(_char);
}

void	Conversion::arg_double(std::string arg)
{
	errno = 0;
	double	d = strtod(arg.c_str(), NULL);
	
	if (errno == ERANGE)
		throw WrongArgs();
	_double = d;
	_float = static_cast<float>(_double);
	_int = static_cast<int>(_double);
	_char = static_cast<char>(_double);
}

std::ostream	&Conversion::printChar(std::ostream &o) const
{
	if (_double < 0 || _double > 127)
		o << "Impossible";
	else if ((_char >= 0 && _char < 32) || _char == 127)
		o << "Non displayable";
	else
		o << "'" << _char << "'";
	return o;
}

std::ostream	&Conversion::printInt(std::ostream &o) const
{
	if (_double < INT_MIN || _double > INT_MAX)
		o << "Impossible";
	else
		o << _int;
	return o;
}

std::ostream	&Conversion::printFloat(std::ostream &o) const
{
	if (_double < FLT_MIN || _double > FLT_MAX)
		o << "Impossible";
	else
		o << _float;
	return o;
}

std::ostream	&Conversion::printDouble(std::ostream &o) const
{
	o << _double;
	return o;
}

std::ostream	&Conversion::printInf(std::ostream &o) const
{
	o << "char: impossible" << std::endl;
	o << "int: impossible" << std::endl;
	o << "float: " << _arg + "f" << std::endl;
	o << "double: " << _arg << std::endl;
	return o;
}

std::ostream	&Conversion::printInff(std::ostream &o) const
{
	o << "char: impossible" << std::endl;
	o << "int: impossible" << std::endl;
	o << "float: " << _arg << std::endl;
	o << "double: " << _arg.substr(0, 2) << std::endl;
	return o;
}

// getter

bool	Conversion::getInf(void) const
{
	return _inf;
}

bool	Conversion::getInff(void) const
{
	return _inff;
}

// non member functions

std::ostream	&operator<<(std::ostream &o, const Conversion &rhs)
{
	o << RESET;
	
	if (rhs.getInf())
		return rhs.printInf(o);
	else if (rhs.getInff())
		return rhs.printInff(o);

	o << "char: ";
	rhs.printChar(o);
	o << std::endl;
	o << "int: ";
	rhs.printInt(o);
	o << std::endl;
	o << "float: ";
	rhs.printFloat(o);
	o << std::endl;
	o << "double: ";
	rhs.printDouble(o);
	o << std::endl;
	return o;
}
