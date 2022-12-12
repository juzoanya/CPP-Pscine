/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:48:09 by juzoanya          #+#    #+#             */
/*   Updated: 2022/12/12 19:48:13 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	robin("Robin");
	robin.announce();

	Zombie	*wolverine;
	wolverine = newZombie("Wolverine");
	wolverine->announce();

	randomChump("Aquaman");

	delete wolverine;
	return (0);
}