

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*horde;

	horde = zombieHorde(5, "X-Men");
	delete[] horde;
	return (0);
}