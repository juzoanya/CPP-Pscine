/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:49:39 by juzoanya          #+#    #+#             */
/*   Updated: 2022/12/12 19:49:44 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	
	if (N <= 0)
	{
		std::cout << "Number of Zombies must be greater than 0" << std::endl;
		return (NULL);
	}
	horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		horde[i].setName(name);
		horde[i].announce();
	}
	return (horde);
}