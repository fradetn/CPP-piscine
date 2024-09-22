
#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
    // Création de deux objets ClapTrap
    ClapTrap bob("Bob");
    ClapTrap jim("Jim");

	std::cout << std::endl;
	bob.setAttackDmg(3);
    // Test de l'attaque
    bob.attack("Jim");
    jim.takeDamage(bob.getAttackDmg());

	std::cout << std::endl;
    // Test de la réparation
    bob.beRepaired(5);

    jim.beRepaired(5);
	std::cout << std::endl;
    // Test des points d'énergie et de vie épuisés
    for (int i = 0; i < 9; i++) {
       		bob.attack("Jim");
       		jim.takeDamage(bob.getAttackDmg());
	}
	std::cout << std::endl;
	jim.attack("Bob");
    // Tentative de réparation sans énergie
    bob.beRepaired(10);

	std::cout << std::endl;
    return 0;
}