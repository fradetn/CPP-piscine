/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:49:03 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/01 11:49:57 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(/* args */) {
	this->type = "?type?";
	std::cout << "WrongAnimal constructor" << std::endl;
}
WrongAnimal::WrongAnimal(WrongAnimal const &src) {
	*this = src;
}
WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor" << std::endl;
}

std::string const &WrongAnimal::getType() const {
	return (this->type);
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {
	this->type = rhs.getType();
	return (*this);
}

void WrongAnimal::makeSound() const{
	std::cout << "? Wich Animal am i ?" << std::endl;
}