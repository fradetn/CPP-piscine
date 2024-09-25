/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:54:45 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/25 10:57:33 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap() {
	this->name = "_clap_name";
	std::cout << "DiamondTrap default constructor called!" << std::endl;
}
DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src), FragTrap(src), ScavTrap(src) {
	*this = src;
    std::cout << "DiamondTrap copy constructor called!" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap() {
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