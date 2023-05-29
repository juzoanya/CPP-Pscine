/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:22:17 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/29 14:22:47 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:
		/* data */
	public:
		WrongCat();
		WrongCat(std::string type);
		WrongCat(const WrongCat& src);
		WrongCat& operator=(const WrongCat& rhs);
		~WrongCat();
	
		void	makeSound() const;
};

#endif