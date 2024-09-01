#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

class Zombie {

public :
	Zombie(std::string name);
	~Zombie(void);

	void announce(void);

private:
	std::string name;
};

#endif