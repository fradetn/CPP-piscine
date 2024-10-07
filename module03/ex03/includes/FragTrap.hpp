/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 07:35:37 by nfradet           #+#    #+#             */
/*   Updated: 2024/10/03 17:31:19 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
	/* data */
public:
	FragTrap(void);
	FragTrap(std::string _name);
	FragTrap(FragTrap const &src);
	virtual ~FragTrap();

	FragTrap &operator=(FragTrap const &rhs);
	void highFiveGuys(void);
};

#endif
