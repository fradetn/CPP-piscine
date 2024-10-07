/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:54:59 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/04 14:08:59 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(): AMateria("cure") {
}
Cure::Cure(std::string const & _type): AMateria(_type) {
}
Cure::Cure(Cure const & src) {
    *this = src;
}

std::string const & Cure::getType() const {
    return (this->type);
}
AMateria* Cure::clone() const {
    AMateria *cure  = new Cure(this->getType());
    return cure;
}
void Cure::use(ICharacter& target) {
    std::cout << "* heals " + target.getName() + "'s wounds *" << std::endl;
}

Cure &Cure::operator=(Cure const &rhs) {
    this->type = rhs.type;
    return (*this);
}