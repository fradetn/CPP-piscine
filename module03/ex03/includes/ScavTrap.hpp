/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 07:26:17 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/30 15:12:28 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:
	/* data */
public:
	ScavTrap(void);
	ScavTrap(std::string _name);
	ScavTrap(ScavTrap const &src);
	~ScavTrap();

	ScavTrap &operator=(ScavTrap const &rhs);

	void attack(std::string const & target);
	void guardGate();
};

#endif