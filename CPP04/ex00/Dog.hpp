/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:54:07 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/29 13:13:17 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
	private:
	
	public:
		Dog();
		Dog(std::string type);
		Dog(const Dog& src);
		Dog& operator=(const Dog& rhs);
		~Dog();
	
		void	makeSound() const;
};

#endif