/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:47:07 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/02 02:59:27 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->i = 0;
	this->nbContact = 0;
	// std::cout << "constructor PhoneBook" << std::endl;
	return;
}

PhoneBook::~PhoneBook(void) {
	// std::cout << "destructor PhoneBook" << std::endl;
	return;
}

int PhoneBook::getNbContact(void) {
	
	return (this->nbContact);
}

static bool isValidName(std::string str) {
	if (str.empty()){
		std::cout << std::endl << "\e[31m/!\\ Ne doit pas etre vide /!\\\e[0m" << std::endl;
		return (false);
	}
	if (str.length() > 30){
		std::cout << std::endl << "\e[31m/!\\ Max 30 caractères /!\\\e[0m" << std::endl;
		return (false);
	}
	for (char c : str){
		if (!std::isalpha(c) && c != '-'){
			std::cout << std::endl << "\e[31m/!\\ Lettres et '-' acceptés /!\\\e[0m" << std::endl;
			return (false);
		}
	}
	return (true);
}

static bool isValidNickname(std::string str) {
	if (str.empty()){
		std::cout << std::endl << "\e[31m/!\\ Ne doit pas etre vide /!\\\e[0m" << std::endl;
		return (false);
	}
	if (str.length() > 20){
		std::cout << std::endl << "\e[31m/!\\ Max 20 caractères /!\\\e[0m" << std::endl;
		return (false);
	}
	return (true);
}

static bool isValidPhone(std::string str) {
	if (str.empty()){
		std::cout << std::endl << "\e[31m/!\\ Ne doit pas etre vide /!\\\e[0m" << std::endl;
		return (false);
	}
	if (str.length() != 10){
		std::cout << std::endl << "\e[31m/!\\ 10 chiffres attendus /!\\\e[0m" << std::endl;
		return (false);
	}
	for (char c : str){
		if (!std::isdigit(c)){
			std::cout << std::endl << "\e[31m/!\\ chiffres attendus /!\\\e[0m" << std::endl;
			return (false);
		}
	}
	return (true);
}

void PhoneBook::addContact(void) {
	std::string s[5];
	if (this->i == 8)
		i = 0;
	std::cout << "\e[32mEntrez les informations suivantes :\e[0m" << std::endl;
	do{
		std::cout << "First name     : ";
		getline(std::cin, s[0]);
	}while (isValidName(s[0]) == false);

	do{
		std::cout << "Last name      : ";
		getline(std::cin, s[1]);
	}while (isValidName(s[1]) == false);

	do{
		std::cout << "Nick name      : ";
		getline(std::cin, s[2]);
	}while (isValidNickname(s[2]) == false);

	do{
		std::cout << "Phone number   : ";
		getline(std::cin, s[3]);
	}while (isValidPhone(s[3]) == false);

	do{
		std::cout << "darkest secret : ";
		getline(std::cin, s[4]);
		if (s[4].empty()) {
			std::cout << std::endl << "\e[31m/!\\ Ne doit pas etre vide /!\\\e[0m" << std::endl;
		}
	}while (s[4].empty());
	this->contact[this->i].setFirstName(s[0]);
	this->contact[this->i].setLastName(s[1]);
	this->contact[this->i].setNickName(s[2]);
	this->contact[this->i].setPhoneNumber(s[3]);
	this->contact[this->i].setDarkestSecret(s[4]);
	this->i++;
	if (this->nbContact < 8)
		this->nbContact++;
}

static void affStr(std::string str) {
	std::string substr;
	if (str.length() > 10)
		substr = str.substr(0, 9) + ".";
	else
		substr = str;
	std::cout << std::setw(10) << substr << "|";
}

static bool	checkFormatIndex(std::string str, int nbContact) {
	int	index;
	if (str.empty())
		return (false);
	if (str.length() != 1)
		return (false);
	for (char c : str){
		if (!std::isdigit(c))
			return (false);
	}
	index = std::stoi(str);
	if (index < 1 || index > nbContact)
		return (false);
	return (true);
}

void PhoneBook::tabContact(void) {
	int i = 0;

	std::cout << "\e[32mRépertoire de Contact :\e[0m" << std::endl << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	while (i < this->nbContact){

		std::cout << "|----------|----------|----------|----------|" << std::endl;
		std::cout << "|         " << i + 1 << "|";
		affStr(this->contact[i].getFirstName());
		affStr(this->contact[i].getLastName());
		affStr(this->contact[i].getNickName());
		std::cout << std::endl;
		i++;
	}
}

void PhoneBook::search(void) {
	std::string str;
	int	index;

	if (this->nbContact == 0){
		std::cout << "\e[33mAucun contact enregistrés\e[0m" << std::endl;
		return ;
	}
	this->tabContact();
	std::cout << std::endl << "\e[32mSelectionnez un numero de contact :\e[0m" << std::endl;
	getline(std::cin, str);
	while (checkFormatIndex(str, this->nbContact) == false){
		std::cout << std::endl << "\e[31m/!\\ Entrez un nombre entre 1 et " << nbContact << " (compris) /!\\\e[0m" << std::endl;
		std::cout << "\e[32mSelectionnez un numero de contact :\e[0m" << std::endl;
		getline(std::cin, str);
	}
	index = std::stoi(str) - 1;
	std::cout << std::endl << "\e[36mInfos du contact N°" << index + 1 << std::endl;
	std::cout << "\e[0mFirst Name     : " + this->contact[index].getFirstName() << std::endl;
	std::cout << "Last Name      : " + this->contact[index].getLastName() << std::endl;
	std::cout << "Nickname       : " + this->contact[index].getNickName() << std::endl;
	std::cout << "Phone Number   : " + this->contact[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret : " + this->contact[index].getDarkestSecret() << std::endl;
}
