/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:43:43 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/07 08:13:51 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <exception>

template <typename T>
class Array
{
	private:
		T*				_element;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& src);
		~Array();

		Array& operator=(const Array& rhs);
		T&	operator[](const unsigned int i);

		unsigned int	size(void) const;

		class OutOfBoundsException : public exception
		{
			public:
				const char* what() const throw();
		};
};

template <typename T>
Array<T>::Array() : _element(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n)
{}

template <typename T>
Array<T>::Array(const Array& src)
{}

template <typename T>
Array<T>::~Array()
{}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& rhs)
{}

template <typename T>
T&	Array<T>::operator[](const unsigned int i)
{}
