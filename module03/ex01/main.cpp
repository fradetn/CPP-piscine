
#include <iostream>
#include "ScavTrap.hpp"

int main( void ) {
	ScavTrap jim;
	ScavTrap bob = ScavTrap("Bob");

	std::cout << std::endl;
	
	std::cout << "Bob Hit points: " << bob.getHit() << std::endl;
	std::cout << "Bob Energy: " << bob.getEnergy() << std::endl;
	std::cout << "Bob Attack Dmg: " << bob.getAttackDmg() << std::endl;
	
	std::cout << std::endl;

	jim.setName("Jim");
	jim.guardGate();
	bob.attack("Jim");
	jim.takeDamage(bob.getAttackDmg());

	std::cout << std::endl;

    return 0;
}