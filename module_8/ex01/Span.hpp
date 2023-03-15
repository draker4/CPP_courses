/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:35:25 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/15 16:55:49 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <cstdlib>

class	Span
{
	private:
	
		Span(void);

		unsigned int		_N;
		std::vector<int>	_vec;

	public:
	
		Span(unsigned int N);
		Span(const Span &rhs);
		~Span(void);
		
		Span				&operator=(const Span &rhs);

		unsigned int		getN(void) const;

		void				addNumber(int n);
		void				addNumber(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end);
		void				printList(std::ostream &o) const;
		int					shortestSpan(void);
		int					longestSpan(void);
		
		class	ContainerFull : public std::exception {
			public:
				const char	*what() const throw() { return "Container is already full!"; }
		};
		
		class	SizeTooLow : public std::exception {
			public:
				const char	*what() const throw() { return "Container's size is too low!"; }
		};

};

std::ostream	&operator<<(std::ostream &o, const Span &rhs);

#endif
