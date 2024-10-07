/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 12:05:55 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/03 16:46:59 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() {
    this->type = "?";
}
AMateria::AMateria(std::string const & _type) {
    this->type = _type;
}
AMateria::AMateria(AMateria const & src) {
    *this = src;
}
AMateria::~AMateria() {
}

std::string const & AMateria::getType() const {
    return (this->type);
}

void AMateria::use(ICharacter& target) {
    std::cout << "Amateria target : " << target.getName();
}

AMateria &AMateria::operator=(AMateria const &rhs) {
    this->type = rhs.type;
    return (*this);
}