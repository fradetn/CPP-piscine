/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:46:20 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/30 15:10:55 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void) {
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->name = "default";
	this->hit = 10;
	this->energy = 10;
	this->attackDmg = 0;
}
ClapTrap::ClapTrap(std::string _name) {
	std::cout << "ClapTrap parameter constructor called" << std::endl;
	this->name = _name;
	this->hit = 10;
	this->energy = 10;
	this->attackDmg = 0;
}
ClapTrap::ClapTrap(ClapTrap const &src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	this->name = src.name;
	this->hit = src.hit;
	this->energy = src.energy;
	this->attackDmg = src.attackDmg;

}
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::setName(std::string _name) {
	this->name = _name;
}

std::string ClapTrap::getName(void) const{
	return (this->name);
}
unsigned int ClapTrap::getHit(void) const{
	return (this->hit);
}
unsigned int ClapTrap::getEnergy(void) const{
	return (this->energy);
}
unsigned int ClapTrap::getAttackDmg(void) const{
	return (this->attackDmg);
}

void ClapTrap::setAttackDmg(unsigned int val) {
	this->attackDmg = val;
}

void ClapTrap::attack(std::string const & target) {
	if (this->getEnergy() > 0 && this->hit > 0) {
		this->energy--;
		std::cout << "ClapTrap " + this->getName() + " attacks " + target + ", causing " << this->getAttackDmg() << " points of damage!" << std::endl;
	}
	else {
		std::cout << "ClapTrap " + this->getName() + " have no energy or hit points to attack !" << std::endl;
	}
}
void ClapTrap::takeDamage(unsigned int amount) {
	if (amount > this->getHit()) {
		this->hit = 0;
		std::cout << "ClapTrap " << this->getName() << " is dead!" << std::endl;
	}
	else
	{
		this->hit -= amount;
		std::cout << "ClapTrap " << this->getName() << " takes " << amount << " points of damage!" << std::endl;
		std::cout << "Current hit points: " << this->getHit() << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (this->energy > 0 && this->hit > 0) {
		this->energy--;
		this->hit += amount;
		std::cout << "ClapTrap " << this->getName() << " repairs itself for " << amount << " hit points! " << std::endl;
		std::cout << "Current hit points: " << this->getHit() << std::endl;
	}
	else {
	std::cout << "ClapTrap " << this->getName() << " has no energy or hit points left to repair!" << std::endl;
    }
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
	this->name = rhs.getName();
	this->name = rhs.getHit();
	this->name = rhs.getEnergy();
	this->attackDmg = rhs.getAttackDmg();
	return (*this);
}