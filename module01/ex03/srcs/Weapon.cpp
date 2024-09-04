/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:36:59 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/03 18:09:18 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(const std::string &type): type(type) {
}

Weapon::~Weapon(void) {
}

const std::string &Weapon::getType(void) const{
	return (this->type);
}

void	Weapon::setType(const std::string &newtype){
	this->type = newtype;
}