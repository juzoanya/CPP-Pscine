/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:54:07 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/12 13:43:14 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: Animal
{
	private:
	
	public:
		Dog(void);
		Dog(Dog const &src);
		Dog& operator=(Dog const rhs);
		~Dog();
	
		void	makeSound();
};

#endif