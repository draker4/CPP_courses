/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:57:25 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/21 19:23:45 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed(void);
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &rhs);
		~Fixed(void);
		
		Fixed				&operator=(const Fixed &rhs);

		bool				operator==(const Fixed &rhs) const;
		bool				operator!=(const Fixed &rhs) const;
		bool				operator<(const Fixed &rhs) const;
		bool				operator<=(const Fixed &rhs) const;
		bool				operator>(const Fixed &rhs) const;
		bool				operator>=(const Fixed &rhs) const;

		Fixed				operator+(const Fixed &rhs) const;
		Fixed				operator-(const Fixed &rhs) const;
		Fixed				operator*(const Fixed &rhs) const;
		Fixed				operator/(const Fixed &rhs) const;

		Fixed				&operator++(void);
		Fixed				operator++(int);
		Fixed				&operator--(void);
		Fixed				operator--(int);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		float				toFloat(void) const;
		int					toInt(void) const;
		
		static Fixed		&min(Fixed &lhs, Fixed &rhs);
		static const Fixed	&min(const Fixed &lhs, const Fixed &rhs);
		static Fixed		&max(Fixed &lhs, Fixed &rhs);
		static const Fixed	&max(const Fixed &lhs, const Fixed &rhs);

	private:
		int					_value;
		static const int	_frac_bit = 8;
};

	std::ostream			&operator<<(std::ostream &o, const Fixed &rhs);

#endif
