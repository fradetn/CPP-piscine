/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:10:53 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/03 18:08:52 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(const std::string &name): name(name), wp(NULL) {
}

HumanB::~HumanB() {
}

void HumanB::attack(void) const{
	if (this->wp)
		std::cout << this->name << " attacks with their " << this->wp->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon to attack with !" << std::endl;
}

void HumanB::setWeapon(Weapon &wp) {
	this->wp = &wp;
}