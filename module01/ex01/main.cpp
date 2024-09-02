/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 23:36:38 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/02 02:47:36 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Zombie.h"

int main()
{
	Zombie *newZomb;
	Zombie *tmp;
	int		i = 0;

	newZomb = zombieHorde(12, "Jean");
	tmp = newZomb;
	while (i < 12) {
		tmp->announce();
		tmp++;
		i++;
	}
	delete [] newZomb;
	return 0;
}
