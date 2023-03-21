/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 21:20:26 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/21 16:26:56 by bperriol         ###   ########lyon.fr   */
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
		
		void				mergeSortMap(std::map<int, int>::iterator begin, std::map<int, int>::iterator end);
		void				mergeSortDeque(std::deque<int>::iterator begin, std::deque<int>::iterator end);
		void				mergeMap(std::map<int, int>::iterator left, std::map<int, int>::iterator med, std::map<int, int>::iterator right);
		void				mergeDeque(std::deque<int>::iterator left, std::deque<int>::iterator med, std::deque<int>::iterator right);
		void				insertionDeque(std::deque<int>::iterator begin, std::deque<int>::iterator end);
		void				insertionMap(std::map<int, int>::iterator begin, std::map<int, int>::iterator end);
		int					prev_value(std::map<int, int>::iterator it);

	public:

		PmergeMe(std::map<int, int> map);
		PmergeMe(std::deque<int> deque);
		PmergeMe(const PmergeMe &rhs);
		~PmergeMe(void);

		PmergeMe			&operator=(const PmergeMe &rhs);
		
		void				print_init(void) const;
		void				print_sort(void) const;
		void				print_time(void) const;
};

#endif
