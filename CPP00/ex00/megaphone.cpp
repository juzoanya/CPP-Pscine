/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juzoanya <juzoanya@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:46:50 by juzoanya          #+#    #+#             */
/*   Updated: 2022/12/12 19:46:54 by juzoanya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	if (argc > 1)
	{
		for (i = 1; argv[i] != NULL; i++)
		{
			for (j = 0; argv[i][j]; j++)
				std::cout << (char)toupper(argv[i][j]);
			if (argv[i + 1] != NULL)
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}