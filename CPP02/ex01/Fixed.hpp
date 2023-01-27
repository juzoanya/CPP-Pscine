/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:40:40 by juzoanya          #+#    #+#             */
/*   Updated: 2023/01/27 16:39:50 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_nbr;
		static int const	_bit;

	public:
		Fixed(void);
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed& nbr);
		Fixed& operator=(const Fixed& nbr);
		Fixed& operator<<(const Fixed& nbr);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& obj, Fixed const & rhs);

#endif