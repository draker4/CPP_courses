/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperriol <bperriol@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:11:30 by bperriol          #+#    #+#             */
/*   Updated: 2023/03/03 14:02:26 by bperriol         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "colors.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

//destructor

Base::~Base(void)
{
	std::cout << YELLOW_F << "Default Base destructor" << RESET << std::endl;
}

// constructor

Base::Base(void)
{
	std::cout << YELLOW_F << "Default Base contructor" << RESET << std::endl;
}

Base::Base(const Base &rhs)
{
	*this = rhs;
	std::cout << YELLOW_F << "Copy Base constructor" << RESET << std::endl;
}

// operator overloads

Base	&Base::operator=(const Base &rhs)
{
	(void)rhs;
	std::cout << YELLOW_F << "Copy Base assignement operator" << RESET << std::endl;
	return *this;
}



// non member functions

Base	*generate(void)
{
	int	random = rand() % 3;

	switch (random)
	{
		case 0:
			return new A();
			break ;
		case 1:
			return new B();
			break ;
		case 2:
			return new C();
			break ;
		default:
			std::cout << RED_B << "error in the random number generated" << RESET << std::endl;
	}
	return NULL;
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e) {}
	try
	{
		B	&b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch (std::exception &e) {}
	try
	{
		C	&c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch (std::exception &e) {}
}
