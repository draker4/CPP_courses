/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:20:37 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/01 13:31:16 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"

class	Intern
{
	private:

	public:
	
		Intern(void);
		Intern(const Intern &rhs);
		~Intern(void);
		
		Intern	&operator=(const Intern &rhs);
		
		AForm	*makeForm(std::string name, std::string target);
};

#endif
