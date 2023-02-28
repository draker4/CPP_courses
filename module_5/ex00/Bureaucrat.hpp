/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:38:44 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/28 10:17:00 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUERAUCRAT_HPP

# include <iostream>

class	Bureaucrat
{
	private:

		Bureaucrat(void);

		const std::string	_name;
		unsigned int		_grade;
		
	public:

		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &rhs);
		~Bureaucrat(void);
		
		Bureaucrat			&operator=(const Bureaucrat &rhs);
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char	*what() const throw() { return "Grade too high!"; }
		};
		
		class GradeTooLowException : public std::exception {
			public:
				virtual const char	*what() const throw() { return "Grade too low!"; }
		};
		
		const std::string	getName(void) const;
		unsigned int		getGrade(void) const;
		void				increment(void);
		void				decrement(void);

};

std::ostream	&operator<<(std::ostream &o, const Bureaucrat &rhs);

#endif
