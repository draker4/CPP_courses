/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Conversion.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:05:36 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/02 12:50:09 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <sstream>

class   Conversion
{
    private:

        std::string _type;
        int         _int;
        char        _char;
        float       _float;
        double      _double;
        
    public:

        Conversion(void);
        Conversion(std::string arg);
        Conversion(const Conversion &rhs);
        ~Conversion(void);
        
        Conversion  &operator=(const Conversion &rhs);
        
        class   WrongArgs : public std::exception {
            const char  *what() const throw() { return "Wrong argument(s)!"; };
        };
};

std::string Convert(const std::string arg);

#endif
