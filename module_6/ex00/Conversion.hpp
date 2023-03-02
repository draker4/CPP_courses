/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:05:36 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/02 18:05:06 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

#include <iostream>
#include <cstdlib>
#include <limits.h>
#include <float.h>
#include <errno.h>


class   Conversion
{
    private:
    
        Conversion(void);

		std::string		_arg;

        int				_int;
        char			_char;
        float			_float;
        double			_double;

		bool			_inf;
		bool			_inff;
        
    public:

        Conversion(std::string arg);
        Conversion(const Conversion &rhs);
        ~Conversion(void);
        
        Conversion		&operator=(const Conversion &rhs);
        
        void			Convert(const std::string arg);
        
        void    		arg_char(std::string arg);
        void   			arg_int(std::string arg);
        void			arg_float(std::string arg);
        void			arg_double(std::string arg);

		std::ostream	&printInf(std::ostream &o) const;
		std::ostream	&printInff(std::ostream &o) const;
		std::ostream	&printChar(std::ostream &o) const;
        std::ostream	&printInt(std::ostream &o) const;
        std::ostream	&printFloat(std::ostream &o) const;
        std::ostream	&printDouble(std::ostream &o) const;
        
		bool			getInf(void) const;
		bool			getInff(void) const;

        class   WrongArgs : public std::exception {
            const char  *what() const throw() { return "Wrong argument(s)!"; };
        };
};

std::ostream    &operator<<(std::ostream &o, const Conversion &rhs);

#endif
