/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:04:08 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/19 15:41:26 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "ShrubberyCreationForm.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructors & operators                          */
/* -------------------------------------------------------------------------- */

ShrubberyCreationForm::ShrubberyCreationForm(void) : 
AForm("shrubbery creation", 145, 137) {
	this->target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string _target) : 
AForm("shrubbery creation", 145, 137) {
	this->target = _target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :
AForm("shrubbery creation", 145, 137) {
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	this->target = rhs.target;
	return (*this);
}

// std::ostream& operator<<(std::ostream &os, ShrubberyCreationForm const & obj) {
	
// }

/* -------------------------------------------------------------------------- */
/*                              Members functions                             */
/* -------------------------------------------------------------------------- */

void ShrubberyCreationForm::executeAction() const {
    std::fstream file;
	
	std::string filename = this->target + "_shrubbery";
	file.open(filename.c_str(), std::fstream::out);
	if (!file.is_open()) {
		std::cerr << "Erreur : Impossible de creer le fichier" << this->target + "_shrubbery" << std::endl;
		return;
	}
	    file << "    ccee88oo" << std::endl;
    file << "  C8O8O8Q8PoOb o8oo" << std::endl;
    file << " dOB69QO8PdUOpugoO9bD" << std::endl;
    file << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
    file << "    6OuU  /p u gcoUodpP" << std::endl;
    file << "      \\\\\\//  /douUP" << std::endl;
    file << "        |||/\\" << std::endl;
    file << "        |||\\/" << std::endl;
    file << "        |||||" << std::endl;
    file << "  .....//||||\\...." << std::endl;

	file.close();
}

AForm *ShrubberyCreationForm::clone(std::string _target) const {
	return (new ShrubberyCreationForm(_target));
}
