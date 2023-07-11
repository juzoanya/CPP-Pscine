/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:40:52 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/11 19:33:29 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int	main(void)
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);

	// Print the elements using iterator
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	// Print the elements in reverse using reverse iterator
	// MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	// MutantStack<int>::reverse_iterator rite = mstack.rend();
	// while (rit != rite) {
	// 	std::cout << *rit << std::endl;
	// 	++rit;
	// }

	// Create a std::stack using MutantStack
	std::stack<int> s(mstack);

	return(0);
}