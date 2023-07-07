/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:50:56 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/06 08:12:27 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data		data;
	Serializer	serializer;
	uintptr_t	serialized;
	Data*		deserialized;

	data.value = 42;
	serialized = serializer.serialize(&data);
	deserialized = serializer.deserialize(serialized);
	std::cout << "Original pointer: " << &data << "| Value: "<< data.value << std::endl;
	std::cout << "Deserialized: " << deserialized << "| Value: " << deserialized->value << std::endl;
	if (&data == deserialized)
		std::cout << "Serializer successful!" << std::endl;
	else
		std::cout << "Serializer unsuccessful!" << std::endl;

	return (0);
}