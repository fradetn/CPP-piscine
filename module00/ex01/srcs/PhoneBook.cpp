/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:47:07 by nfradet           #+#    #+#             */
/*   Updated: 2024/08/30 17:18:38 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void){
	this->i = 0;
	this->nbContact = 0;
	std::cout << "constructor PhoneBook" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void){
	std::cout << "destructor PhoneBook" << std::endl;
	return;
}

int PhoneBook::getNbContact(void){
	
	return (this->nbContact);
}

void PhoneBook::addContact(void)
{
	std::string s;
	if (this->i == 8)
		i = 0;
	std::cout << "Entrez les informations suivantes :" << std::endl;
	std::cout << "First name : ";
	getline(std::cin, s);
	this->contact[this->i].setFirstName(s);
	std::cout << "Last name : ";
	getline(std::cin, s);
	this->contact[this->i].setLastName(s);
	std::cout << "Nick name : ";
	getline(std::cin, s);
	this->contact[this->i].setNickName(s);
	std::cout << "Phone number : ";
	getline(std::cin, s);
	this->contact[this->i].setPhoneNumber(s);
	std::cout << "darkest secret : ";
	getline(std::cin, s);
	this->contact[this->i].setDarkestSecret(s);
	this->i++;
	this->nbContact++;
}

void PhoneBook::search(void){
	int i = 0;
	
	std::cout << "     INDEX|FIRST NAME| LAST NAME|  NICKNAME" << std::endl;
	while (i < this->nbContact){

		std::cout << "----------|----------|----------|----------" << std::endl;
		std::cout << "         " + std::to_string(i) + "|";
		//utilisation de la fonction "setw()"
		
		i++;
	}
	// std::cout << "          |          |          " << std::endl;

}