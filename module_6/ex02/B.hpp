/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:15:21 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 13:22:34 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_HPP
# define B_HPP

# include "Base.hpp"

class	B : public Base
{
	private:

	public:
	
		B(void);
		B(const B &rhs);
		~B(void);

		B	&operator=(const B &rhs);
};

#endif
