/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 00:57:47 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/02 02:46:57 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
	Zombie *horde;
	Zombie *temp;
	int		i = 0;

	horde = new Zombie[N];
	temp = horde;
	while (i < N) {
		temp->setName(name);
		temp++;
		i++;
	}
	return (horde);
}
