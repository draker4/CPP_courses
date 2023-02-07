/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:09:08 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/07 10:03:53 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <ios>
# include <limits>
# include <iomanip>

class Contact
{
	private:
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
		int			_index;

		std::string	_getString(std::string str) const;

	public :
		Contact();
		~Contact();
		
		void	initContact(void);
		void	setIndex(int index);
		void	print_name(int index) const;
		void	print_all(int index) const;
};

#endif
