/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:58:32 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/03 18:06:59 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weaponRef) : name(name), wp(weaponRef)  {
}

HumanA::~HumanA() {
}

void HumanA::attack(void) const{
	std::cout << this->name << " attacks with their " << this->wp.getType() << std::endl;
}