/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:09:54 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 13:43:00 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>

class	Base
{
	private:
	
	public:
	
		Base(void);
		Base(const Base &rhs);
		virtual	~Base(void);
		
		Base	&operator=(const Base &rhs);

};

Base	*generate(void);
void	identify(Base *p);
void	identify(Base& p);

#endif
