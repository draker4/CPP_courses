/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:49:40 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/21 18:52:03 by bperriol         ###   ########lyon.fr   */
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

Fixed::Fixed(const float value) : _value(std::roundf(value * (1 << _frac_bit)))
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
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
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

bool	Fixed::operator==(const Fixed &rhs) const
{
	return _value == rhs.getRawBits();
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return _value != rhs.getRawBits();
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return _value < rhs.getRawBits();
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return _value <= rhs.getRawBits();
}

bool	Fixed::operator>(const Fixed &rhs) const
{
	return _value > rhs.getRawBits();
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return _value >= rhs.getRawBits();
}

Fixed	Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++(void)
{
	_value++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);
	_value++;
	return tmp;
}

Fixed	&Fixed::operator--(void)
{
	_value--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);
	_value--;
	return tmp;
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return lhs;
	return rhs;
}

const Fixed	&Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return lhs;
	return rhs;
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return lhs;
	return rhs;
}

const Fixed	&Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return lhs;
	return rhs;
}
