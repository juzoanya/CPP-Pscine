/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:48:54 by juzoanya          #+#    #+#             */
/*   Updated: 2022/12/12 19:48:59 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
# define ZOMBIE_H

# include <iostream>

class Zombie
{
private:
	std::string	_name;

public:
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);
};

Zombie*	newZombie(std::string	name);
void	randomChump(std::string	name);

#endif