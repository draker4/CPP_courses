/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:48:43 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/22 12:38:51 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "colors.hpp"

Point::Point(void) : _x(0), _y(0)
{
	std::cout << CYAN_F << "Default Point constructor called" << std::endl;
}

Point::Point(float x, float y) : _x(x), _y(y)
{
	std::cout << CYAN_F << "Float Point constructor called" << std::endl;
}

Point::Point(const Point &rhs) : _x(rhs._x), _y(rhs._y)
{
	std::cout << CYAN_F << "Copy Point constructor called" << std::endl;
}

Point::~Point(void)
{
	std::cout << CYAN_F << "Point destructor called" << std::endl;
}

Point	&Point::operator=(const Point &rhs)
{
	const_cast<Fixed&> (_x) = rhs.getX();
	const_cast<Fixed&> (_y) = rhs.getY();
	return *this;
}

const Fixed &Point::getX(void) const
{
	return _x;
}

const Fixed &Point::getY(void) const
{
	return _y;
}

void	Point::setX(const Fixed &rhs)
{
	const_cast<Fixed&> (_x) = rhs;
}

void	Point::setY(const Fixed &rhs)
{
	const_cast<Fixed&> (_y) = rhs;
}

std::ostream	&operator<<(std::ostream &o, const Point &rhs)
{
	o << "x = " << rhs.getX() << "  y = " << rhs.getY() << "  ";
	return o;
}
