/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:57:15 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 16:03:22 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(/* args */) {
	this->type = "?type?";
	std::cout << "AAnimal constructor" << std::endl;
}
AAnimal::AAnimal(AAnimal const &src) {
	*this = src;
}
AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor" << std::endl;
}

std::string const &AAnimal::getType() const {
	return (this->type);
}

AAnimal &AAnimal::operator=(AAnimal const &rhs) {
	this->type = rhs.getType();
	return (*this);
}
