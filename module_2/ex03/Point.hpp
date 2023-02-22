/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:47:56 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/22 13:17:30 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
	public:
		Point(void);
		Point(float x, float y);
		Point(const Point &rhs);
		~Point(void);
		
		Point	&operator=(const Point &rhs);
		
		const Fixed	&getX(void) const;
		const Fixed	&getY(void) const;
		void	setX(const Fixed &rhs);
		void	setY(const Fixed &rhs);
	
	private:
		const	 Fixed	_x;
		const	 Fixed	_y;
};

std::ostream	&operator<<(std::ostream &o, const Point &rhs);

#endif
