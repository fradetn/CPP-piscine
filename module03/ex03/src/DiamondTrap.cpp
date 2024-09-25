/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:54:45 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/24 14:16:40 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap() {
	this->hit = FragTrap::hit;
	this->energy = ScavTrap::energy;
	this->attackDmg = FragTrap::attackDmg;
	std::cout << "DiamondTrap default constructor called!" << std::endl;
}
DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src){
	*this = src;
    std::cout << "DiamondTrap copy constructor called!" << std::endl;
}
DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name){
	this->name = name;
	this->hit = 100;
	this->energy = 100;
	this->attackDmg = 30;
    std::cout << "DiamondTrap parameter constructor called!" << std::endl;
}
DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap destructeur called!" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs){
	if (this != &rhs)
		ClapTrap::operator=(rhs);
    std::cout << "DiamondTrap copy operator called!" << std::endl;
	return (*this);
}

void DiamondTrap::highFiveGuys() {
    std::cout << "DiamondTrap " << this->getName() << " is asking for a positive high five!" << std::endl;
}
