/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 11:23:30 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 17:20:27 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	PresidentialPardonForm(void);

	std::string _target;

public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm(void);

	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	
	virtual void		execute(Bureaucrat const & executor) const;
};

#endif
