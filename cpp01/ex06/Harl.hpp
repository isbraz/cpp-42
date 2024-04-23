#ifndef HARL_HPP
#define HARL_HPP

# include <iostream>
# include <string>

#define RED "\033[41m"
#define GREEN "\033[92m"
#define RESET "\033[0m"

class Harl{
	public:
			void complain(std::string level);
	private:
			void debug(void);
			void info(void);
			void warning(void);
			void error(void);
};

#endif