/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:49:19 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/06 14:02:28 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <algorithm>

template <typename T>
class	ValueNotFound : public std::exception
{
	private:
		std::string	_str;
	public:
		ValueNotFound(T value) {
			std::ostringstream o;
				o << "Value " << value << " not found";
				_str = o.str();
		}
		virtual const char	*what() const throw() { return _str.c_str(); }
};

template <typename T>
int	easyfind(T &container, int to_find)
{
	typename T::iterator it = std::find(container.begin(), container.end(), to_find);
	if (it != container.end())
		return *it;
	else
		throw ValueNotFound<int>(to_find);
	return 0;
}

#endif
