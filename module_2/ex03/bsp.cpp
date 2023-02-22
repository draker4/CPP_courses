/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:38:29 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/22 13:25:51 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	area(Point a, Point b, Point c)
{
	Fixed	area;

	area = (a.getX() * (b.getY() - c.getY())
			+ (b.getX() * (c.getY() - a.getY()))
			+ (c.getX() * (a.getY() - b.getY()))) / 2;
	if (area > 0)
		return area;
	else
		return area * (-1);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaPAB, areaPBC, areaPCB, areaABC;

	areaPAB = area(point, a, b);
	areaPBC = area(point, b, c);
	areaPCB = area(point, c, b);
	areaABC = area(a, b, c);
	
	if (areaPAB != 0 && areaPBC != 0 && areaPCB != 0 && areaABC == areaPAB + areaPBC + areaPCB)
		return true;
	return false;
}
