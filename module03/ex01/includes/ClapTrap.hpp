/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:58:46 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/30 15:14:22 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
	std::string name;
	unsigned int	hit;
	unsigned int	energy;
	unsigned int	attackDmg;

public:
	ClapTrap(void);
	ClapTrap(std::string _name);
	ClapTrap(ClapTrap const &src);
	~ClapTrap();

	void setName(std::string _name);

	std::string getName(void) const;
	unsigned int getHit(void) const;
	unsigned int getEnergy(void) const;
	unsigned int getAttackDmg(void) const;

	void setAttackDmg(unsigned int val);

	void attack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	ClapTrap & operator=(ClapTrap const & rhs);
};

#endif