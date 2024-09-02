#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

class Zombie {

public :
	Zombie(void);
	~Zombie(void);

	void announce(void);
	std::string getName(void);
	void setName(std::string name);

private:
	std::string name;
};

#endif