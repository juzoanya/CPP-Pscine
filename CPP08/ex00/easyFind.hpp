/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 08:06:20 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/09 21:45:27 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <vector>
# include <stdexcept>
# include <iostream>
# include <algorithm>
# include <list>
class ValueNotFoundException : public std::exception
{
	public:
		const char* what() const throw()
		{
			return("Value not Found");
		}
};

template <class T>
typename T::iterator easyFind(T& container, int toFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it != container.end())
		return it;
	else
		throw ValueNotFoundException();
}

#endif
