/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:36:22 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/03 18:06:38 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
	
private:
	std::string type;

public:
	Weapon(const std::string &type);
	~Weapon(void);

	const std::string &getType(void) const;
	void		setType(const std::string &newtype);
	
};

#endif