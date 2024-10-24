/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:45:57 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/24 17:30:04 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

Character::Character() {
	std::cout << "def constructor called" << std::endl;
    this->name = "default";
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(std::string const &_name) {
	std::cout << "name constructor called" << std::endl;
    this->name = _name;
	for (int i = 0; i < 4; i++) {
		this->inventory[i] = NULL;
	}
}

Character::Character(Character const &src) {
    *this = src;
}

Character::~Character() {
	std::cout << "destructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL) {
			delete this->inventory[i];
			this->inventory[i] = NULL;
		}
	}
}

std::string const & Character::getName() const {
    return (this->name);
}
void Character::equip(AMateria* m) {
	if (m == NULL)
		return;
	if (m->getIsEquiped() == true) {
		std::cout << m->getType() << " already equiped" << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] == NULL) {
			std::cout << "Materia " << m->getType() << " has been equiped" << std::endl;
			this->inventory[i] = m;
			this->inventory[i]->setIsEquiped(true);
			return;
		}
	}
	std::cout << "Can't equip " << m->getType() << std::endl;
}
void Character::unequip(int idx) {
	for (int i = 0; i < 4; i++) {
		if (i == idx && this->inventory[i] != NULL) {
			std::cout << "Materia " << this->inventory[i]->getType() << " has been unequiped" << std::endl;
			this->inventory[i]->setIsEquiped(false);
			this->inventory[i] = NULL;
			return;
		}
	}
	std::cout << "Can't unequip materia at index " << idx << std::endl;
}
void Character::use(int idx, ICharacter& target) {
	for (int i = 0; i < 4; i++) {
		if (i == idx && this->inventory[i] != NULL) {
			this->inventory[i]->use(target);
			return;
		}
	}
	std::cout << "Can't use materia at index " << idx << std::endl;
}

void Character::showInventory() const {
	std::cout << std::endl;
	std::cout << this->name + "'s inventory: " << &this->name << std::endl;
	for (int i = 0; i < 4; i++) {
		if (this->inventory[i] != NULL)
			std::cout <<"materia[" << i << "] : " << this->inventory[i]->getType() << "  " << this->inventory[i] << std::endl;
		else
			std::cout <<"materia[" << i << "] : NOTHING" << std::endl;
	}
	std::cout << std::endl;
}

Character &Character::operator=(Character const &rhs) {
    if (this != &rhs) {
        this->name = rhs.name;

        // Clean up the current inventory
        for (int i = 0; i < 4; i++) {
            if (this->inventory[i] != NULL) {
                delete this->inventory[i];
                this->inventory[i] = NULL;
            }
        }

        // Deep copy of rhs's inventory
        for (int i = 0; i < 4; i++) {
            if (rhs.inventory[i] != NULL) {
                this->inventory[i] = rhs.inventory[i]->clone();
            } else {
                this->inventory[i] = NULL;
            }
        }
    }
    return *this;
}