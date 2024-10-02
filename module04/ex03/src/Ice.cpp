/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 13:45:20 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/02 16:43:11 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(): AMateria("ice") {

}
Ice::Ice(std::string const & _type): AMateria(_type) {
    this->type = _type;
}
Ice::Ice(Ice const & src) {
    *this = src;
}

std::string const & Ice::getType() const {
    return (this->type);
}
AMateria* Ice::clone() const {
    std::cout << "cloning : " << this->getType() << std::endl;
    AMateria *ice = new Ice(this->getType());
    return (ice);
}
void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " + target.getName() + " *" << std::endl;
}

Ice &Ice::operator=(Ice const &rhs) {
    this->type = rhs.type;
    return (*this);
}