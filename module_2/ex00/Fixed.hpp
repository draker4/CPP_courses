/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 16:57:25 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/21 11:56:37 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &rhs);
		~Fixed(void);
		
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		Fixed				&operator=(const Fixed &rhs);

	private:
		int					_value;
		static const int	_frac_bit = 8;
};

#endif
