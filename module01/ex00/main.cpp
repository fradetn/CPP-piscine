/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:36:38 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 10:28:55 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.hpp"

void	randomChump(std::string name);
Zombie	*newZombie(std::string name);

int main()
{
	Zombie *newZomb;

	randomChump("RandomChump");
	newZomb = newZombie("NewZombie");
	newZomb->announce();
	delete newZomb;
	return 0;
}