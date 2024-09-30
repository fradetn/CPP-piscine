/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:54:45 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/30 15:03:49 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap() {
	this->name = "default";
	this->ClapTrap::name = name + "_clap_name";
    this->FragTrap::hit = 100;
    this->ScavTrap::energy = 50;
    this->FragTrap::attackDmg = 30;
	std::cout << "DiamondTrap default constructor called!" << std::endl;
}
DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), FragTrap(src), ScavTrap(src) {
	*this = src;
    std::cout << "DiamondTrap copy constructor called!" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name){
    this->name = name;
	this->ClapTrap::name = name + "_clap_name";
	
    this->FragTrap::hit = 100;
    this->ScavTrap::energy = 50;
    this->FragTrap::attackDmg = 30;
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
	std::cout << "name: " << this->getName() << std::endl;
	std::cout << "hit: " << this->getHit() << std::endl;
	std::cout << "energy: " << this->getEnergy() << std::endl;
	std::cout << "attackDmg: " << this->getAttackDmg() << std::endl;
}

void DiamondTrap::WhoAmI(void) {
	std::cout << "FragTrap name: " << this->getName() << std::endl;
	std::cout << "DiamondTrap name: " << this->name << std::endl;

}