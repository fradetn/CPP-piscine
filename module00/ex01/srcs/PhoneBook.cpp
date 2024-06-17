/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:47:07 by nfradet           #+#    #+#             */
/*   Updated: 2024/06/18 00:02:09 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	this->i = 0;
	std::cout << "constructor PhoneBook" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void){
	std::cout << "destructor PhoneBook" << std::endl;
	return;
}

void PhoneBook::addContact(void)
{
	Contact person;
	std::string s;

	std::cout << "Entrez les informations suivantes :" << std::endl;
	std::cout << "First name : ";
	getline(std::cin, s);
	person.setFirstName(s);
	std::cout << "Last name : ";
	getline(std::cin, s);
	person.setLastName(s);
	std::cout << "Nick name : ";
	getline(std::cin, s);
	person.setNickName(s);
	std::cout << "Phone number : ";
	getline(std::cin, s);
	person.setPhoneNumber(s);
	std::cout << "darkest secret : ";
	getline(std::cin, s);
	person.setDarkestSecret(s);
	if (this->i < 8)
		this->contact[this->i] = person;

}

// size_t PhoneBook::getNbContact(void){
// 	size_t len;

// 	len = sizeof(this->contact) / sizeof(this->contact[0]);
// 	std::cout << "len de contact = " << len << std::endl;
// 	return (len);
// }