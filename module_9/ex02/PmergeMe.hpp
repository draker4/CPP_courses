/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:20:26 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/14 22:04:12 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include "colors.hpp"
# include <map>
# include <deque>

class	PmergeMe
{
	private:

		PmergeMe(void);
		
		double				_time;
		int					_container;
		std::map<int, int>	_map;
		std::map<int, int>	_map_origin;
		std::deque<int>		_deque;
		std::deque<int>		_deque_origin;
		
	public:

		PmergeMe(std::map<int, int> map);
		PmergeMe(std::deque<int> deque);
		PmergeMe(const PmergeMe &rhs);
		~PmergeMe(void);

		PmergeMe	&operator=(const PmergeMe &rhs);
};

#endif
