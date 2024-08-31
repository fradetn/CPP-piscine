/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:54:19 by nfradet           #+#    #+#             */
/*   Updated: 2024/08/31 16:53:17 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PhoneBook.hpp"

int	main(void){
	PhoneBook repertoire;
	std::string entry;

	while (1){
		std::cout << std::endl << "(Commandes acceptées : \e[32mADD\e[0m, \e[32mSEARCH\e[0m, \e[32mEXIT\e[0m)" << std::endl;
		std::cout << "\e[32mEntrez une commande :\e[0m" << std::endl;
		getline(std::cin, entry);
		std::cout << std::endl;
		
		if (entry.compare("ADD") == 0)
			repertoire.addContact();
		else if (entry.compare("SEARCH") == 0)
			repertoire.search();
		else if (entry.compare("EXIT") == 0)
			return (0);
		else		
			std::cout << "\e[31m/!\\ Commande incorrecte /!\\\e[0m" << std::endl;
	}
}
