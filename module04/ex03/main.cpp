/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:07:05 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/04 20:53:17 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

#include "ICharacter.hpp"
#include "Character.hpp"

int main()
{
	AMateria *ice;
	AMateria *cure;
	AMateria *clone;

	Character bob = Character("Bob");
	Character jim;
	ice = new Ice("ice");
	cure = new Cure();
	clone = cure->clone();

	std::cout << "cure  : " << cure << std::endl;
	std::cout << "ice   : " << ice << std::endl;
	std::cout << "clone : " << clone << std::endl;
	jim.equip(ice);
	jim.showInventory();
	// bob.equip(ice);
	bob.equip(cure);
	bob.equip(clone);
	bob.showInventory();
	jim = bob;
	jim.showInventory();
	bob.showInventory();
	bob.unequip(0);
	std::cout << std::endl;
	bob.showInventory();
	bob.equip(cure);
	std::cout << std::endl;
	bob.showInventory();

	// delete ice;
	// delete cure;
	// delete clone;
	return 0;
}