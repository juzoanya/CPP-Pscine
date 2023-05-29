/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:54:00 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/29 13:12:49 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal
{
	private:
	
	public:
		Cat(void);
		Cat(std::string type);
		Cat(const Cat& src);
		Cat& operator=(const Cat& rhs);
		~Cat();

		void	makeSound() const;
};

#endif