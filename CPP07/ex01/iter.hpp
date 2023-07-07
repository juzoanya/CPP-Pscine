/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:25:23 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/06 19:18:59 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename Iter>
void	iter(Iter* addr, int len, void(*f)(Iter &ref))
{
	if (addr == NULL || len == 0 || f == NULL)
		return;
	for (int i = 0; i < len; i++)
		f(addr[i]);
}

template <typename T>
void	printSpace(T src)
{
	std::cout << src << " ";
}


#endif