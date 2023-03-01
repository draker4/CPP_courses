/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 10:31:57 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 17:34:58 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

class Bureaucrat;

class	AForm
{
	private:

		AForm(void);

		const std::string 	_name;
		bool				_signed;
		const unsigned int	_grade_to_signed;
		const unsigned int	_grade_required;
		
	public:

		AForm(const std::string name, int grade_to_signed, int _grade_required);
		AForm(const AForm &rhs);
		virtual ~AForm(void);

		AForm				&operator=(const AForm &rhs);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw() { return "Grade too high!"; }
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw() { return "Grade too low!"; }
		};
		
		class FormNotSigned : public std::exception {
			public:
				virtual const char	*what() const throw() { return "Form not signed!"; }
		};
		
		class FileNotOpen : public std::exception {
			public:
				virtual void char	*what() const throw() { return "File not open" };
		}
		
		const std::string	getName(void) const;
		unsigned int		getGradeToSigned(void) const;
		unsigned int		getGradeRequired(void) const;
		bool				getSigned(void) const;
		
		void				beSigned(const Bureaucrat &b);
		virtual void		execute(Bureaucrat const & executor) const = 0;
};

std::ostream	&operator<<(std::ostream &o, const AForm &rhs);

#endif
