/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:31:57 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 10:58:03 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class	Form
{
	private:

		Form(void);

		const std::string 	_name;
		bool				_signed;
		const unsigned int	_grade_to_signed;
		const unsigned int	_grade_to_required;
		
	public:

		Form(const std::string name, int grade_to_signed, int grade_to_required);
		Form(const Form &rhs);
		~Form(void);

		Form				&operator=(const Form &rhs);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw() { return "Grade too high!"; }
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw() { return "Grade too low!"; }
		};
		
		const std::string	getName(void) const;
		unsigned int		getGradeToSigned(void) const;
		unsigned int		getGradeToRequired(void) const;
		bool				getSigned(void) const;
		
		void	beSigned(const Bureaucrat &b);
};

std::ostream	&operator<<(std::ostream &o, const Form &rhs);

#endif
