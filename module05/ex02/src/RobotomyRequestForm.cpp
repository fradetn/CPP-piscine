/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:02:59 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/19 18:10:05 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include "RobotomyRequestForm.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructors & operators                          */
/* -------------------------------------------------------------------------- */

RobotomyRequestForm::RobotomyRequestForm(void) :
AForm("Robotomy request form", 72, 45) {
	std::srand((unsigned)std::time(0));
	this->target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string _target) :
AForm("Robotomy request form", 72, 45) {
	std::srand((unsigned)std::time(0));
	this->target = _target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :
AForm("Robotomy request form", 72, 45) {
	std::srand((unsigned)std::time(0));
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	this->target = rhs.target;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              Members functions                             */
/* -------------------------------------------------------------------------- */

void RobotomyRequestForm::executeAction() const {
    std::cout << "******************* Drilling Noises *******************" << std::endl;


	int randomV = std::rand() % 2;

	if (randomV == 0)
		std::cout << this->target << " has been robotomized" << std::endl;
	else
		std::cout << "Robotomy on " << this->target << " has failed" << std::endl;
}