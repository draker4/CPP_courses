/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:02:06 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/09 14:02:35 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>
# include <algorithm>

template < typename T, class Container = std::deque<T> >
class	MutantStack : public std::stack<T, Container>
{
	private:
	
	public:

		MutantStack(void);
		MutantStack(const MutantStack &rhs);
		~MutantStack(void);

		MutantStack	&operator=(const MutantStack &rhs);
		
		typedef typename Container::iterator iterator;
		typename Container::iterator	begin(void);
		typename Container::iterator	end(void);
};

# include "MutantStack.tpp"

#endif
