#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
	private:
			std::string _name;
			Weapon *armB;
	public:
			HumanB(std::string name);
			void setWeapon(Weapon &type);
			void attack();
};

#endif