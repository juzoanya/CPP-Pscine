
#include "Weapon.hpp"

class	HumanA
{
	public:
		HumanA(Weapon &weapon, std::string name);
		~HumanA(void);
		void	attack();
	private:
		std::string	name;
		Weapon		&weapon;
};