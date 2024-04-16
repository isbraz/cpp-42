#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
	private:
			std::string _type;
	public:
			Weapon(std::string type);
			void setType(std::string type);
			const std::string& getType();
};

#endif