/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 07:36:32 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/25 11:01:48 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap() {
	this->hit = 100;
	this->energy = 100;
	this->attackDmg = 30;
	std::cout << "FragTrap default constructor called!" << std::endl;
}
FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src){
	*this = src;
    std::cout << "FragTrap copy constructor called!" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->name = name;
	this->hit = 100;
	this->energy = 100;
	this->attackDmg = 30;
    std::cout << "FragTrap parameter constructor called!" << std::endl;
}
FragTrap::~FragTrap(){
    std::cout << "FragTrap destructeur called!" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs){
	if (this != &rhs)
		ClapTrap::operator=(rhs);
    std::cout << "FragTrap copy operator called!" << std::endl;
	return (*this);
}

void FragTrap::attack(std::string const & target) {
	if (this->getEnergy() > 0 && this->hit > 0) {
		this->energy--;
		std::cout << "FragTrap " + this->getName() + " attacks " + target + ", causing " << this->getAttackDmg() << " points of damage!" << std::endl;
	}
	else {
		std::cout << "FragTrap " + this->getName() + " have no energy or hit points to attack !" << std::endl;
	}
}
void FragTrap::highFiveGuys() {
    std::cout << "FragTrap " << this->getName() << " is asking for a positive high five!" << std::endl;
}
