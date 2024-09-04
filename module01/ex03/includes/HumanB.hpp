/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 16:10:11 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/03 18:08:24 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon *wp;
public:
	HumanB(const std::string &name);
	~HumanB();

	void setWeapon(Weapon &wp);
	void attack() const;
};

#endif