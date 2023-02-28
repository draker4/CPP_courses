/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:23:30 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 11:31:40 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm : public AForm
{
	private:

		ShrubberyCreationForm(void);
		
		std::string _target;

	public:
	
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
		
};

#endif
