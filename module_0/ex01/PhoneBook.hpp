/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:06:48 by bperriol          #+#    #+#             */
/*   Updated: 2023/02/07 10:14:24 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:

		Contact	_contact[8];
		int		_read_index(void) const;
		int		_nb_contacts;

	public:

		PhoneBook();
		~PhoneBook();
	
		void	begin(void);
		void	add(void);
		void	search(void) const;
};

#endif
