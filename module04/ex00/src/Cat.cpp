/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:04:42 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/22 17:51:15 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void){
	this->type = "Cat";
	std::cout << "Cat constructor" << std::endl;
}
Cat::Cat(Cat const &src) {
	*this = src;
}
Cat::~Cat() {
	std::cout << "Cat destructor" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
	this->type = rhs.getType();
	return (*this);
}

void Cat::makeSound() const{
	std::cout << "Meow !" << std::endl;
}