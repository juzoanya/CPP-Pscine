/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:50:39 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/05 21:54:12 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(const Serializer& src)
{
	(void)src;
}

Serializer::~Serializer()
{}

Serializer& Serializer::operator=(const Serializer& rhs)
{
	(void)rhs;
	return(*this);
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}