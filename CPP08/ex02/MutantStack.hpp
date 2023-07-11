/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:41:16 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/11 20:20:51 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack(){}
		MutantStack(const MutantStack& src)
		{
			*this = src;
		}
		~MutantStack(){}

		MutantStack& operator=(const MutantStack& rhs)
		{
			std::stack<T>::operator=(rhs);
			return(*this);
		}

		typedef typename std::stack<T>::container_type::iterator	iterator;
		iterator	begin()
		{
			return(this->c.begin());
		}
		iterator	end()
		{
			return(this->c.end());
		}
};


