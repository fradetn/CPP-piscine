/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:51:00 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/19 18:29:09 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/* -------------------------------------------------------------------------- */
/*                          Constructors & operators                          */
/* -------------------------------------------------------------------------- */

AForm::AForm(void) : name("default"), signRequired(1), execRequired(1) {
}

AForm::AForm(std::string _name, int signReq, int execReq) : 
name(_name), signRequired(signReq), execRequired(execReq) {
	this->isSigned = false;
	if (signReq < 1 || execReq < 1)
		throw AForm::GradeTooHighException();	
	else if (signReq > 150 || execReq > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(AForm const &src)  :
signRequired(src.signRequired), execRequired(src.getExecRequired()) {
	*this = src;
}

AForm::~AForm() {}

AForm & AForm::operator=(AForm const & rhs){
	this->isSigned = rhs.getIsSigned();
	return (*this);
}

std::ostream& operator<<(std::ostream &os, AForm const & obj) {
	if (obj.getIsSigned() == true)
		os << obj.getName() << " \e[32mhas been signed\e[0m, need \e[33mgrade " << obj.getExecRequired() << "\e[0m to execute this form.";
	else
		os << obj.getName() << " \e[31mis not signed\e[0m, need \e[33mgrade " << obj.getSignRequired() << "\e[0m to sign this form.";
	return (os);
}

/* -------------------------------------------------------------------------- */
/*                              Getters & setters                             */
/* -------------------------------------------------------------------------- */

std::string const & AForm::getName(void) const {
	return (this->name);
}
bool AForm::getIsSigned(void) const {
	return (this->isSigned);
}
int const & AForm::getSignRequired(void) const {
	return (this->signRequired);
}
int const & AForm::getExecRequired(void) const {
	return (this->execRequired);
}

/* -------------------------------------------------------------------------- */
/*                              Members function                              */
/* -------------------------------------------------------------------------- */

void AForm::beSigned(Bureaucrat const &bur) {
	if (this->isSigned == true)
		throw AForm::FormAlreadySignedException();
	if (bur.getGrade() <= this->getSignRequired())
		this->isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const {
	if (this->getIsSigned() == false) {
		throw AForm::FormNotSignedException();
		return;
	}
	else if (executor.getGrade() > this->getExecRequired()) {
		throw AForm::GradeTooLowException();
		return;
	}
	executeAction();
}

const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade is too low [1;150]");
}

const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade is too high [1;150]");
}

const char *AForm::FormNotSignedException::what() const throw() {
	return ("Form is not signed yet !");
}

const char *AForm::FormAlreadySignedException::what() const throw() {
	return ("Form is already signed !");
}