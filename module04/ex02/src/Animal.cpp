/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 16:57:15 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 16:03:22 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(/* args */) {
	this->type = "?type?";
	std::cout << "Animal constructor" << std::endl;
}
Animal::Animal(Animal const &src) {
	*this = src;
}
Animal::~Animal() {
	std::cout << "Animal destructor" << std::endl;
}

std::string const &Animal::getType() const {
	return (this->type);
}

Animal &Animal::operator=(Animal const &rhs) {
	this->type = rhs.getType();
	return (*this);
}
