/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:08:12 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/22 17:51:13 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void){
	this->type = "Dog";
	std::cout << "Dog constructor" << std::endl;
}
Dog::Dog(Dog const &src) {
	*this = src;
}
Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;	
}

Dog &Dog::operator=(Dog const &rhs) {
	this->type = rhs.getType();
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Wouf !" << std::endl;
}
