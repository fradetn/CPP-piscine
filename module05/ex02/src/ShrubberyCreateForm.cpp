/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreateForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:04:08 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/18 20:44:13 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include "ShrubberyCreateForm.hpp"

ShrubberyCreateForm::ShrubberyCreateForm(void) : 
Form("Shrubbery creation form", 145, 137) {
	this->target = "default";
}

ShrubberyCreateForm::ShrubberyCreateForm(std::string _target) : 
Form("Shrubbery creation form", 145, 137) {
	this->target = _target;
}

ShrubberyCreateForm::ShrubberyCreateForm(ShrubberyCreateForm const &src) :
Form("Shrubbery creation form", 145, 137) {
	*this = src;
}

ShrubberyCreateForm::~ShrubberyCreateForm() {}

ShrubberyCreateForm &ShrubberyCreateForm::operator=(ShrubberyCreateForm const &rhs) {
	this->target = rhs.target
}

void ShrubberyCreateForm::execute(Bureaucrat const &executor) const {
	if (this->getIsSigned() == false) {
		throw Form::FormNotSignedException();
		return;
	}
	else if (executor.getGrade() > this->getExecRequired()) {
		throw Form::GradeTooLowException();
		return;
	}
	
    std::ofstream file(this->target + "_shrubbery");
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