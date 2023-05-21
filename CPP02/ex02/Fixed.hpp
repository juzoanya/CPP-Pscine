/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:40:40 by juzoanya          #+#    #+#             */
/*   Updated: 2023/05/21 17:29:06 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_nbr;
		static int const	_bit = 8;

	public:
		Fixed(void);
		Fixed(const int nbr);
		Fixed(const float nbr);
		Fixed(const Fixed& src);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();

		bool operator>(const Fixed& rhs);
		bool operator<(const Fixed& rhs);
		bool operator>=(const Fixed& rhs);
		bool operator<=(const Fixed& rhs);
		bool operator==(const Fixed& rhs);
		bool operator!=(const Fixed& rhs);

		Fixed operator+(const Fixed& rhs);
		Fixed operator-(const Fixed& rhs);
		Fixed operator*(const Fixed& rhs);
		Fixed operator/(const Fixed& rhs);

		Fixed& operator++();
		Fixed& operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		//Fixed& operator<<(const Fixed& rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		static			Fixed& min(Fixed& a, Fixed& b);
		static			Fixed& max(Fixed& a, Fixed& b);
		static const	Fixed& min(const Fixed& a, const Fixed& b);
		static const	Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& obj, Fixed const & rhs);

#endif