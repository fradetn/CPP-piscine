/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 11:47:37 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/01 11:47:39 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void){
	this->type = "WrongCat";
	std::cout << "WrongCat constructor" << std::endl;
}
WrongCat::WrongCat(WrongCat const &src) {
	*this = src;
}
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	this->type = rhs.getType();
	return (*this);
}

void WrongCat::makeSound() const{
	std::cout << "Meow !" << std::endl;
}