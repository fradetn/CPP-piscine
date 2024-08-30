/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:54:19 by nfradet           #+#    #+#             */
/*   Updated: 2024/08/30 16:52:50 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/PhoneBook.hpp"

int	main(void){
	PhoneBook repertoire;

	repertoire.addContact();
	repertoire.search();
	// repertoire.getNbContact();
	// std::cout << contact.getFirstName() << std::endl;
	// std::cout << contact.getLastName() << std::endl;
	// std::cout << contact.getNickName() << std::endl;
	// std::cout << contact.getPhoneNumber() << std::endl;
	// std::cout << contact.getDarkestSecret() << std::endl;
}
