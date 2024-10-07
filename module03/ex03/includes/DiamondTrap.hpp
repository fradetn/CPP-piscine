#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string name;
public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap const &src);
	virtual ~DiamondTrap();

	DiamondTrap &operator=(DiamondTrap const &rhs);
	void displayStats(void);
	void attack(std::string const & target);
	void WhoAmI(void);
};

#endif
