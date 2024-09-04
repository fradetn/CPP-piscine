/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 15:54:43 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/03 18:07:05 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon &wp;
public:
	HumanA(const std::string &name, Weapon &weaponRef);
	~HumanA();

	void attack() const;
};

#endif