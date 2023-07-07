/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 18:16:13 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/06 18:18:27 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename Swap>
void	swap(Swap &a, Swap &b)
{
	Swap	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename Min>
Min		&min(Min &a, Min &b)
{
	return (a < b ? a : b);
}

template <typename Max>
Max		&max(Max &a, Max &b)
{
	return (a > b ? a : b);
}

#endif