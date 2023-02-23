/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:49:40 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/23 13:52:58 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>
#include "colors.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << RED_F << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const int value) : _value(value << _frac_bit)
{
	std::cout << RED_F << "Int constructor called" << RESET << std::endl;
}

Fixed::Fixed(const float value) : _value(roundf(value * (1 << _frac_bit)))
{
	std::cout << RED_F << "Float constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << RED_F << "Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

Fixed::~Fixed(void)
{
	std::cout << RED_F << "Destructor called" << RESET << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << RED_F << "getRawBits member function called" << RESET << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << RED_F << "setRawBits member function called" << RESET << std::endl;
	_value = raw;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << RED_F << "Copy assignement operator called" << RESET << std::endl;
	_value = rhs.getRawBits();
	return *this;
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _frac_bit));
}

int	Fixed::toInt(void) const
{
	return (_value >> _frac_bit);
}

std::ostream &operator<<(std::ostream &o, const Fixed &rhs)
{
	o << rhs.toFloat();
	return o;
}
