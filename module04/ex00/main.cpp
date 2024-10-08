/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:07:05 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/01 11:51:38 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"

int main()
{
	const Animal* meta = new Animal();
	std::cout << std::endl;
	const Animal* j = new Dog();
	std::cout << std::endl;
	const Animal* i = new Cat();
	std::cout << std::endl;
	const WrongAnimal* k = new WrongCat();
	std::cout << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	std::cout << k->getType() << std::endl;
	std::cout << meta->getType() << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();
	meta->makeSound();

	std::cout << std::endl;
	delete j;
	j = i;
	std::cout << j->getType() << std::endl;
	j->makeSound();
	std::cout << std::endl;
	delete i;
	std::cout << std::endl;
	delete meta;
	return 0;
}