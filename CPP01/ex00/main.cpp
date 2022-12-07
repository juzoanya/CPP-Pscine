

#include "Zombie.hpp"

int	main(void)
{
	Zombie	robin("Robin");
	robin.announce();

	Zombie	*wolverine;
	wolverine = newZombie("Wolverine");
	wolverine->announce();

	randomChump("Aquaman");

	delete wolverine;
	return (0);
}