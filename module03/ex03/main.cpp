/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 07:42:02 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/22 07:46:15 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	FragTrap jim;
	FragTrap bob = FragTrap("Bob");

	std::cout << std::endl;
	
	std::cout << "Bob Hit points: " << bob.getHit() << std::endl;
	std::cout << "Bob Energy: " << bob.getEnergy() << std::endl;
	std::cout << "Bob Attack Dmg: " << bob.getAttackDmg() << std::endl;
	
	std::cout << std::endl;

	jim.setName("Jim");
	jim.highFiveGuys();
	bob.attack("Jim");
	jim.takeDamage(bob.getAttackDmg());

	std::cout << std::endl;

    return 0;
}
