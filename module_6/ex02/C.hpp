/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:15:21 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 13:22:41 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef C_HPP
# define C_HPP

# include "Base.hpp"

class	C : public Base
{
	private:

	public:
	
		C(void);
		C(const C &rhs);
		~C(void);

		C	&operator=(const C &rhs);
};

#endif
