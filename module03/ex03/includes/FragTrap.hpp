/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 07:35:37 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/22 07:45:54 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
	/* data */
public:
	FragTrap(void);
	FragTrap(std::string name);
	FragTrap(FragTrap const &src);
	~FragTrap();

	FragTrap &operator=(FragTrap const &rhs);

	void highFiveGuys(void);
};

#endif
