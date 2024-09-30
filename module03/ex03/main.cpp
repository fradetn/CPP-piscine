/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 07:42:02 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/30 15:04:22 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) {
	DiamondTrap diams("diams");
	DiamondTrap d;

	std::cout << std::endl;
	
	d.WhoAmI();
	d.attack("test");
	d.highFiveGuys();
	diams.WhoAmI();
	diams.displayStats();
	diams.attack("test");
	std::cout << std::endl;

    return 0;
}
