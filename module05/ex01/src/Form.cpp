/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:51:00 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/18 19:38:22 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/* -------------------------------------------------------------------------- */
/*                          Constructors & operators                          */
/* -------------------------------------------------------------------------- */

Form::Form(void) : name("default"), signRequired(1), execRequired(1) {
}

Form::Form(std::string _name, int signReq, int execReq) : 
name(_name), signRequired(signReq), execRequired(execReq) {
	this->isSigned = false;
	if (signReq < 1 || execReq < 1)
		throw Form::GradeTooHighException();	
	else if (signReq > 150 || execReq > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src)  :
signRequired(src.signRequired), execRequired(src.getExecRequired()) {
	*this = src;
}

Form::~Form() {}

Form & Form::operator=(Form const & rhs){
	this->isSigned = rhs.getIsSigned();
	return (*this);
}

std::ostream& operator<<(std::ostream &os, Form const & obj) {
	if (obj.getIsSigned() == true)
		os << obj.getName() << " \e[32mhas been signed\e[0m, need \e[33mgrade " << obj.getExecRequired() << "\e[0m to execute this form.";
	else
		os << obj.getName() << " \e[31mis not signed\e[0m, need \e[33mgrade " << obj.getSignRequired() << "\e[0m to sign this form.";
	return (os);
}

/* -------------------------------------------------------------------------- */
/*                              Getters & setters                             */
/* -------------------------------------------------------------------------- */

std::string const & Form::getName(void) const {
	return (this->name);
}
bool Form::getIsSigned(void) const {
	return (this->isSigned);
}
int const & Form::getSignRequired(void) const {
	return (this->signRequired);
}
int const & Form::getExecRequired(void) const {
	return (this->execRequired);
}

/* -------------------------------------------------------------------------- */
/*                              Members function                              */
/* -------------------------------------------------------------------------- */

void Form::beSigned(Bureaucrat const &bur) {
	if (bur.getGrade() <= this->getSignRequired())
		this->isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade is too low [1;150]");
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade is too high [1;150]");
}