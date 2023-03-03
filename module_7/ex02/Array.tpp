/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:52:26 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 17:25:15 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include <sstream>

template <typename T>
class	Array
{
	private:
		
		unsigned int	_size;
		T				*_array;

	public:
	
		Array(void) : _size(0), _array(new T[0]) {
			std::cout << GREEN_F << "Default Array constructor" << RESET << std::endl;
		}
		
		Array(unsigned int n) : _size(n), _array(new T[n]) {
			std::cout << GREEN_F << "Unsigned int Array constructor" << RESET << std::endl;
		}

		Array(const Array &rhs) {
			*this = rhs;
			std::cout << GREEN_F << "Copy Array constructor" << std::endl;
		}
		~Array(void) {
			delete [] _array;
			std::cout << GREEN_F << "Default Array destructor" << RESET << std::endl;
		}
		
		Array	&operator=(const Array &rhs) {
			delete [] _array;
			_size = rhs._size;
			_array = new T[rhs._size];
			for (unsigned int i = 0; i < rhs._size; i++)
				_array[i] = rhs._array[i];
			std::cout << GREEN_F << "Copy Array assignement operator" << std::endl;
			return *this;
		}
		
		T	&operator[](unsigned int idx) const {
			if (idx >= _size)
				throw OutOfBounds(idx);
			return _array[idx];
		}
		
		unsigned int	size(void) const {
			return _size;
		}
		
		class	OutOfBounds : public std::exception {
			
			private:
			
				std::string	_str;

			public:
			
				OutOfBounds(unsigned int idx) {
					std::ostringstream o;
					o << "Index " << idx << " out of bounds";
					_str = o.str();
				}
				~OutOfBounds() throw() {}
				virtual const char	*what() const throw() { return _str.c_str(); };
		};

};

#endif
