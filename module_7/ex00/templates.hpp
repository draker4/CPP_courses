/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:21:29 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 15:25:27 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

template <typename T>
void	swap(T &x, T &y)
{
	T	tmp;
	
	tmp = x;
	x = y;
	y = tmp;
}

template <typename T>
T	&min(T &x, T &y)
{
	return ( x < y ? x : y);
}

template <typename T>
T	&max(T &x, T &y)
{
	return ( x > y ? x : y);
}

#endif
