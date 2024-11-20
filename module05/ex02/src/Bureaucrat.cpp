/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:46:20 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/20 14:39:57 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructors & operators                          */
/* -------------------------------------------------------------------------- */

Bureaucrat::Bureaucrat(void) : name("default"), grade(150){
}
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
			this->grade = grade;
}
Bureaucrat::Bureaucrat(Bureaucrat const &src) {
	*this = src;
}
Bureaucrat::~Bureaucrat() {}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
	this->grade = rhs.grade;
	return (*this);
}

std::ostream& operator<<(std::ostream &os, Bureaucrat const & obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

/* -------------------------------------------------------------------------- */
/*                              Getters & setters                             */
/* -------------------------------------------------------------------------- */

std::string const Bureaucrat::getName(void) const {
	return (this->name);
}

int Bureaucrat::getGrade(void) const {
	return (this->grade);
}

/* -------------------------------------------------------------------------- */
/*                              Member functions                              */
/* -------------------------------------------------------------------------- */

void Bureaucrat::incrementGrade(void) {
	if (this->getGrade() - 1 < 1)
			throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decrementGrade(void) {
	if (this->getGrade() + 1 > 150)
			throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade cannot be higher than 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade cannot be lower than 150");
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}
