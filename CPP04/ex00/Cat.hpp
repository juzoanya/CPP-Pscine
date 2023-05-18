/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:54:00 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/12 14:00:32 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : Animal
{
	private:
	
	public:
		Cat(void);
		Cat(std::string type);
		Cat(Cat const &src);
		Cat& operator=(Cat const &rhs);
		~Cat();

		void	makeSound();
};


#endif;