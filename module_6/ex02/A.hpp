/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:15:21 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/09 11:44:18 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_HPP
# define A_HPP

# include "Base.hpp"

class	A : public Base
{
	private:

	public:
	
		A(void);
		A(const A &rhs);
		~A(void);

		A	&operator=(const A &rhs);
};

#endif
