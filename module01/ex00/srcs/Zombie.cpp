/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:03:09 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/02 00:31:56 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->name = name;
	std::cout << "\e[0;32mCreating <" << this->name << ">\e[0;0m"<<std::endl;
	return ;
}
Zombie::~Zombie(void) {
	std::cout << "\e[0;31mDestroying <" << this->name << ">\e[0;0m"<<std::endl;
	return ;
}

void Zombie::announce(void) {
	std::cout << this->name + ":  BraiiiiiiinnnzzzZ..." << std::endl;
}
