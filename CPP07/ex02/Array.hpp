/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 20:43:43 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/08 21:26:30 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <exception>
#include <stdlib.h>

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

		class OutOfBoundsException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

template <typename T>
Array<T>::Array() : _element(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n)
{
	this->_element = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_element[i] = T();
}

template <typename T>
Array<T>::Array(const Array& src) : _size(src._size)
{
	this->_element = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_element[i] = src._element[i];
}

template <typename T>
Array<T>::~Array()
{
	if (this->_element)
		delete[] this->_element;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& rhs)
{
	delete[] this->_element;
	this->_size = rhs._size;
	this->_element = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_element[i] = rhs._element[i];
	return(*this);
}

template <typename T>
T&	Array<T>::operator[](const unsigned int i)
{
	if (i > this->_size)
		throw Array::OutOfBoundsException();
	return(this->_element[i]);

}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return(this->_size);
}

template <typename T>
const char*	Array<T>::OutOfBoundsException::what() const throw()
{
	return("Out of bounds exception");
}
