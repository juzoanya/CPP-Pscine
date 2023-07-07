/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 20:50:33 by juzoanya          #+#    #+#             */
/*   Updated: 2023/07/06 08:06:20 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include <stdint.h>

class Serializer
{
	private:
		/* data */
	public:
		Serializer();
		Serializer(const Serializer& src);
		~Serializer();

		Serializer& operator=(const Serializer& rhs);

		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);
};
