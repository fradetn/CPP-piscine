/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:54:45 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/07 16:11:43 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap("default_clap_trap") {
	this->name = "default";
    this->hit = FragTrap::hit;
    this->energy = 50;
    this->attackDmg = FragTrap::attackDmg;
	std::cout << "DiamondTrap default constructor called!" << std::endl;
}
DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), ScavTrap(src), FragTrap(src) {
	*this = src;
    std::cout << "DiamondTrap copy constructor called!" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap") {
    this->name = name;
    this->hit = FragTrap::hit;
    this->energy = 50;
    this->attackDmg = FragTrap::attackDmg;
	std::cout << "DiamondTrap parameter constructor called!" << std::endl;
}
DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap destructeur called!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs){
	if (this != &rhs)
		ScavTrap::operator=(rhs);
    std::cout << "DiamondTrap copy operator called!" << std::endl;
	return (*this);
}

void DiamondTrap::displayStats()
{
	std::cout << "name: " << this->name << std::endl;
	std::cout << "hit: " << this->hit << std::endl;
	std::cout << "energy: " << this->energy << std::endl;
	std::cout << "attackDmg: " << this->attackDmg << std::endl;
}

void DiamondTrap::WhoAmI(void) {
	std::cout << "FragTrap name: " << this->getName() << std::endl;
	std::cout << "DiamondTrap name: " << this->name << std::endl;

}

void DiamondTrap::attack(std::string const & target) {
	ScavTrap::attack(target);
}