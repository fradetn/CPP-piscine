/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:51:00 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/14 01:05:55 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <iostream>

/* -------------------------------------------------------------------------- */
/*                          Constructors & operators                          */
/* -------------------------------------------------------------------------- */

Form::Form(/* args */) : name("default"), signRequired(1), execRequired(1) {
}

Form::Form(std::string _name, int signReq, int execReq) : name(_name), signRequired(signReq), execRequired(execReq) {
	if (signReq < 0 || execReq < 0)
		throw Form::GradeTooHighException();	
	else if (signReq > 150 || execReq > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src) {
	*this = src;
}

Form::~Form() {}

/* -------------------------------------------------------------------------- */
/*                              Getters & setters                             */
/* -------------------------------------------------------------------------- */

std::string const & getName(void) const {
	return (this->name);
}
boolean getIsSigned(void) const {
	return (this->isSigned);
}
int const & getSignRequired(void) const {
	return (this->signRequired);

}
int const & getExecRequired(void) const {
	return (this->execRequired);
}