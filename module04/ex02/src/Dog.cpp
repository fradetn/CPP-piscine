/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:08:12 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 15:56:47 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(void){
	std::cout << "Dog constructor" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}
Dog::Dog(Dog const &src) {
	std::cout << "Dog copy constructor" << std::endl;
	*this = src;
}

Dog::~Dog() {
	std::cout << "Dog destructor" << std::endl;
	delete this->brain;
}

Dog &Dog::operator=(Dog const &rhs) {
	this->type = rhs.getType();
	this->brain = rhs.brain;
	return (*this);
}

void Dog::makeSound() const{
	std::cout << "Wouf !" << std::endl;
}
