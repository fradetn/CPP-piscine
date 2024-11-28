/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:16:32 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/19 18:18:37 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructors & operators                          */
/* -------------------------------------------------------------------------- */

PresidentialPardonForm::PresidentialPardonForm(void) :
AForm("Presidential pardon form", 25, 5) {
	std::srand((unsigned)std::time(0));
	this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string _target) :
AForm("Presidential pardon form", 25, 5) {
	std::srand((unsigned)std::time(0));
	this->target = _target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :
AForm("Presidential pardon form", 25, 5) {
	std::srand((unsigned)std::time(0));
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	this->target = rhs.target;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              Members functions                             */
/* -------------------------------------------------------------------------- */

void PresidentialPardonForm::executeAction() const {
		std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}