/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:34:30 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/30 15:12:46 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap() {
	this->hit = 100;
	this->energy = 50;
	this->attackDmg = 20;
	std::cout << "ScavTrap default constructor called!" << std::endl;
}
ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src){
	*this = src;
    std::cout << "ScavTrap copy constructor called!" << std::endl;
}
ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name){
	this->name = _name;
	this->hit = 100;
	this->energy = 50;
	this->attackDmg = 20;
    std::cout << "ScavTrap parameter constructor called!" << std::endl;
}
ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap destructeur called!" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs){
	if (this != &rhs)
		ClapTrap::operator=(rhs);
    std::cout << "ScavTrap copy operator called!" << std::endl;
	return (*this);
}

void ScavTrap::attack(std::string const & target) {
	if (this->getEnergy() > 0 && this->hit > 0) {
		this->energy--;
		std::cout << "ScavTrap " + this->getName() + " attacks " + target + ", causing " << this->getAttackDmg() << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ScavTrap " + this->getName() + " have no energy or hit points to attack !" << std::endl;
	}
}
void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() << " is now in Gate Keeper mode!" << std::endl;
}
