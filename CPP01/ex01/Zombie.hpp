/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:49:31 by juzoanya          #+#    #+#             */
/*   Updated: 2022/12/12 19:49:34 by juzoanya         ###   ########.fr       */
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
	Zombie(void);
	Zombie(std::string name);
	~Zombie(void);
	void	announce(void);
	void	setName(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif