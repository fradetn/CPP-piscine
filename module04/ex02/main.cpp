/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:07:05 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/30 16:12:22 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const AAnimal *j[10];
	const AAnimal *k;
	
	// k = new AAnimal();
	// delete k;

	std::cout << "---------- constructors ----------" << std::endl;
	for (int i = 0; i < 10; i++) {
		if (i < 5)
			j[i] = new Dog();
		else 
			j[i] = new Cat();
	}
	std::cout << std::endl;
	
	k = j[0];
	std::cout << &k << std::endl;
	std::cout << &j[0] << std::endl;

	std::cout << std::endl;
	
	std::cout << std::endl << "---------- destructors ----------" << std::endl;

	for (int i = 0; i < 10; i++) {
		delete j[i];
	}

	return 0;
}