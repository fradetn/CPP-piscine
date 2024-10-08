/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:27:22 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/05 16:27:22 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <string>
#include <iostream>

class Harl {

private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
public:
	Harl(/* args */);
	~Harl();

	void complain(std::string level);
};

typedef void (Harl::*funcHarl_t)(void);

#endif