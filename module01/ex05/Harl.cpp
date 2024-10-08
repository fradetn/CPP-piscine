/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:03:45 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/05 16:25:58 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Harl.hpp"

#define DEBUG  "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
#define INFO  "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!"
#define WARNING  "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month."
#define ERROR  "This is unacceptable! I want to speak to the manager now."

Harl::Harl(/* args */) {
}

Harl::~Harl() {
}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << DEBUG << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << INFO << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << WARNING << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << ERROR << std::endl;
}

void Harl::complain(std::string level) {
	funcHarl_t func_tab[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	while (i < 4) {
		if (levels_tab[i].compare(level) == 0)
			(this->*func_tab[i])();
		i++;
	}	
}