/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 13:27:24 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/29 13:15:04 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	protected:
		std::string _type;
	
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& src);
		Animal& operator=(const Animal& rhs);
		~Animal();

		void	makeSound() const;
		std::string	getType() const;
	
};

#endif