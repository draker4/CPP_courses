/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 10:49:40 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/21 11:49:31 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include "colors.hpp"

Fixed::Fixed(void) : _value(0)
{
	std::cout << RED_F << BOLD << "Default constructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &rhs)
{
	std::cout << RED_F << BOLD << "Copy constructor called" << RESET << std::endl;
	*this = rhs;
}

Fixed::~Fixed(void)
{
	std::cout << RED_F << BOLD << "Destructor called" << RESET << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << RED_F << BOLD << "getRawBits member function called" << RESET << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << RED_F << BOLD << "setRawBits member function called" << RESET << std::endl;
	_value = raw;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << RED_F << BOLD << "Copy assignement operator called" << RESET << std::endl;
	_value = rhs.getRawBits();
	return *this;
}
