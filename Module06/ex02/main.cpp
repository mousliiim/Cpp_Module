/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmourdal <mmourdal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:57:39 by mmourdal          #+#    #+#             */
/*   Updated: 2023/06/29 23:04:02 by mmourdal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cmath>

Base *generate(void)
{
	int i = rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
			A &a = dynamic_cast<A&>(p);
			std::cout << "A" << std::endl;
			(void)a;
	}
	catch ( std::exception &error )
	{
		std::cout << "Its not type A | Catch error : " << error.what() << std::endl;
	};
	try
	{
			B &b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
			(void)b;
	}
	catch ( std::exception &error )
	{
		std::cout << "Its not type B | Catch error : " << error.what() << std::endl;
	};
	try
	{
			C &c = dynamic_cast<C&>(p);
			std::cout << "C" << std::endl;
			(void)c;
	}
	catch ( std::exception &error )
	{
		std::cout << "Its not type C | Catch error : " << error.what() << std::endl;
	};
}

int main ( void )
{
	srand(time(NULL));
	Base *base = generate();
	identify(base);
	identify(*base);

	delete base;
	return (0);
}