/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 08:24:22 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/06 09:58:48 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void)
{
	int	rand = std::rand() % 3;
	switch (rand)
	{
		case 0:
			return(new A);
		case 1:
			return(new B);
		case 2:
			return(new C);
		default:
			return(NULL);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "This is an instance of A Class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "This is an instance of B Class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "This is an instance of C Class" << std::endl;
	else
		std::cout << "No Class found for this instance" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "This is a reference to Class A" << std::endl;
		return;
	}
	catch(const std::exception& e){}
	try
	{
		dynamic_cast<B&>(p);
		std::cout << "This is a reference to Class B" << std::endl;
		return;
	}
	catch(const std::exception& e){}
	try
	{
		dynamic_cast<C&>(p);
		std::cout << "This is a reference to Class C" << std::endl;
		return;
	}
	catch(const std::exception& e){}
}

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i <= 9; i++)
	{
		std::cout << "Test#" << i + 1 << std::endl;
		Base *test = generate();
		identify(test);
		Base	&ref = *test;
		identify(ref);
		std::cout << "**********"<< std::endl;
		delete test;
	}
}