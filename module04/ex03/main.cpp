/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:07:05 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/02 16:42:48 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

int main()
{
	AMateria *ice;
	AMateria *cure;
	AMateria *clone;


	ice = new Ice();
	cure = new Cure();

	std::cout << ice->getType() << std::endl;
	clone = ice->clone();
	// std::cout << ice->getType() << std::endl;
	// std::cout << cure->getType() << std::endl;
	std::cout << clone->getType() << std::endl;
	// ice->use();
	return 0;
}