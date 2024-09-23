/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 01:15:28 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/23 10:46:19 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Sed.hpp"

Sed::Sed(std::string filename) : fileIn(filename) {
	this->fileOut = this->fileIn + ".replace";
}

Sed::~Sed(void) {
}

void Sed::replace(std::string toFind, std::string toReplace) {
	std::string str;
	std::fstream ifs;
	std::fstream ofs;
	(void) toFind;
	(void) toReplace;
	size_t pos;

	ifs.open(this->fileIn, std::fstream::in);
	ofs.open(this->fileOut, std::fstream::out);
    if (!ifs.is_open()) {
        std::cout << "Error opening input file" << std::endl;
        exit(EXIT_FAILURE);
	}
    if (!ofs.is_open()) {
        std::cout << "Error opening output file" << std::endl;
        exit(EXIT_FAILURE);
    }
	getline(ifs, str, '\0');
	pos = 0;
	while (pos < str.length()) {
		pos = str.find(toFind, pos);
		if (pos != std::string::npos) {
			str.erase(pos, toFind.length());
			str.insert(pos, toReplace);
			pos += toReplace.length();
		}
	}
	ofs << str;
	ifs.close();
	ofs.close();
}
