/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 17:16:45 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/04 18:42:20 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap bob("Bob");
	ClapTrap jim("Jim");

	bob.attack("Jim");
	jim.takeDamage(5);
	jim.beRepaired(5);
	bob.attack("Jim");
	jim.takeDamage(5);
	jim.attack("Bob");
}