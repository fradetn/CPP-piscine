#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ClapTrap, public ScavTrap
{
private:
	std::string DiamondName;
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &src);
	~DiamondTrap();

	DiamondTrap &operator=(DiamondTrap const &rhs);

	void highFiveGuys(void);
};

#endif
