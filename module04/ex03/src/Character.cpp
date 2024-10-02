/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 11:45:57 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/02 16:01:03 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"


Character() {
    this->name = "";
}

Character(std::string const &_name) {
    this->name = _name;
}

Character(Character const &src) {
    this = src;
}

~Character() {}

std::string const & getName() const {
    return (this->name);
}
void equip(AMateria* m) {

}
void unequip(int idx) {

}
void use(int idx, Character& target) {

}

Character &operator=(Character const &rhs) {
    
}