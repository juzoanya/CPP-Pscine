
#include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(Weapon &weapon, std::string name);
		~HumanB(void);
		void	attack();
		void	setWeapon(Weapon &weapon);
	
	private:
		std::string	name;
		Weapon		&weapon;
};