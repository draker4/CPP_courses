/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:07:52 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/09 13:58:17 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "colors.hpp"

// destructor

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack(void)
{
	std::cout << YELLOW_F << "Default MutantStack destructor" << RESET << std::endl;
}

// constructor

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>()
{
	std::cout << YELLOW_F << "Default MutantStack contructor" << RESET << std::endl;
}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &rhs) : std::stack<T>(rhs)
{
	*this = rhs;
	std::cout << YELLOW_F << "Copy MutantStack contructor" << RESET << std::endl;
}

// operator overload

template <typename T, class Container>
MutantStack<T, Container>	&MutantStack<T, Container>::operator=(const MutantStack<T, Container> &rhs)
{
	std::stack<T, Container>::operator=(rhs);
	std::cout << YELLOW_F << "Copy MutantStack assignement operator" << RESET << std::endl;
	return *this;
}

// iterators

template <typename T, class Container>
typename Container::iterator	MutantStack<T, Container>::begin(void)
{
	return this->c.begin();
}

template <typename T, class Container>
typename Container::iterator	MutantStack<T, Container>::end(void)
{
	return this->c.end();
}
