/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:04:42 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 15:57:01 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(void){
	std::cout << "Cat constructor" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}
Cat::Cat(Cat const &src) {
	std::cout << "Cat copy constructor" << std::endl;
	*this = src;
}
Cat::~Cat() {
	delete this->brain;
	std::cout << "Cat destructor" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
	this->type = rhs.getType();
	this->brain = rhs.brain;
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Meow !" << std::endl;
}