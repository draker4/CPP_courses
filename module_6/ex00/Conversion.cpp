/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:05:25 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 12:32:56 by bperriol         ###   ########lyon.fr   */
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

Conversion::Conversion(void): _arg(""), _int(0), _char('\0'), _float(0.0f), _double(0.0), _inf(false), _inff(false)
{
	std::cout << RED_F << "Default Conversion constructor" << std::endl;
}

Conversion::Conversion(std::string arg) : _arg(arg), _int(0), _char('\0'), _float(0.0f), _double(0.0), _inf(false), _inff(false)
{
	Convert();
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
	_inf = rhs._inf;
	_inff = rhs._inff;
	std::cout << RED_F << "Copy Conversion assignement operator" << std::endl;
	return *this;
}

// member functions

void	Conversion::Convert(void)
{
	int	nb_point = 0;

	if (!_arg.compare("-inff") || !_arg.compare("inff") || !_arg.compare("nanf"))
	{
		_inff = true;
		std::cout << RESET << CYAN_B << "arg is a float" << RESET << std::endl;
		return ;
	}
	else if (!_arg.compare("-inf") || !_arg.compare("inf") || !_arg.compare("nan"))
	{
		_inf = true;
		std::cout << RESET << CYAN_B << "arg is a double" << RESET << std::endl;
		return ;
	}
	if (_arg[0] == '+' || _arg[0] == '-' || std::isdigit(_arg[0]))
	{
		if (!_arg[1] && !std::isdigit(_arg[0]))
			return arg_char();
		else if (_arg.substr(1).find_first_not_of("0123456789") == std::string::npos)
			return arg_int();
		else
		{
			for (size_t i = 1; i < _arg.length(); i++)
			{
				if (i == _arg.length() - 1 && _arg[i] == 'f')
					return arg_float();
				if (_arg[i] == '.')
					nb_point++;
				if ((!std::isdigit(_arg[i]) && _arg[i] != '.') || nb_point > 1)
					throw WrongArgs();
			}
			return arg_double();
		}
	}
	if (_arg.length() == 1)
		return arg_char();
	throw WrongArgs();
}

void	Conversion::arg_float(void)
{
	errno = 0;
	double	d = strtod(_arg.c_str(), NULL);
	
	if (errno == ERANGE || d < -std::numeric_limits<float>::max() || d > std::numeric_limits<float>::max())
		throw WrongArgs();
	std::cout << RESET << CYAN_B << "arg is a float" << RESET << std::endl;
	_float = strtof(_arg.c_str(), NULL);
	_int = static_cast<int>(_float);
	_double = static_cast<double>(_float);
	_char = static_cast<char>(_float);
}

void	Conversion::arg_int(void)
{
	long int	li = strtol(_arg.c_str(), NULL, 10);

	if (errno == ERANGE || li > std::numeric_limits<int>::max() || li < std::numeric_limits<int>::min())
		return arg_double();
	std::cout << RESET << CYAN_B << "arg is an int" << RESET << std::endl;
	_int = std::atoi(_arg.c_str());
	_float = static_cast<float>(_int);
	_double = static_cast<double>(_int);
	_char = static_cast<char>(_int);
}

void	Conversion::arg_char(void)
{
	std::cout << RESET << CYAN_B << "arg is a char" << RESET << std::endl;
	_char = _arg[0];
	_float = static_cast<float>(_char);
	_double = static_cast<double>(_char);
	_int = static_cast<int>(_char);
}

void	Conversion::arg_double(void)
{
	errno = 0;
	_double = strtod(_arg.c_str(), NULL);
	if (errno == ERANGE)
		throw WrongArgs();
	std::cout << RESET << CYAN_B << "arg is a double" << RESET << std::endl;
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
	if (_double < std::numeric_limits<int>::min() || _double > std::numeric_limits<int>::max())
		o << "Impossible";
	else
		o << _int;
	return o;
}

std::ostream	&Conversion::printFloat(std::ostream &o) const
{
	size_t	precision = 1;
	size_t	pos = _arg.find_first_of(".");

	if (_double < -std::numeric_limits<float>::max() || _double > std::numeric_limits<float>::max())
		o << "Impossible";
	else
	{
		if (pos != std::string::npos)
		{
			while (_arg[pos + 1] != '\0' && _arg[pos + 1] != 'f')
			{
				if (pos != _arg.find_first_of("."))
					precision++;
				pos++;
			}
		}
		o << std::setprecision(precision) << std::fixed << _float;
		o << "f";
	}
	return o;
}

std::ostream	&Conversion::printDouble(std::ostream &o) const
{
	size_t	precision = 1;
	size_t	pos = _arg.find_first_of(".");

	if (pos != std::string::npos)
	{
		while (_arg[pos + 1] != '\0' && _arg[pos + 1] != 'f')
			{
				if (pos != _arg.find_first_of("."))
					precision++;
				pos++;
			}
	}
	o << std::setprecision(precision) << std::fixed << _double;
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
	o << "double: " << _arg.substr(0, 4) << std::endl;
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
