#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>
#include <iostream>

/* -------------------------------------------------------------------------- */
/*                          Constructors & operators                          */
/* -------------------------------------------------------------------------- */

Intern::Intern(void) {
	this->forms[0] = new ShrubberyCreationForm();
	this->forms[1] = new RobotomyRequestForm();
	this->forms[2] = new PresidentialPardonForm();
}
Intern::Intern(Intern const &src) {
	(void) src;
	this->forms[0] = new ShrubberyCreationForm();
	this->forms[1] = new RobotomyRequestForm();
	this->forms[2] = new PresidentialPardonForm();
}
Intern::~Intern() {
	delete forms[0];
	delete forms[1];
	delete forms[2];
}

Intern & Intern::operator=(Intern const & rhs) {
	(void) rhs;
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	int i = 0;
	for (; i < 3 && this->forms[i]->getName().compare(formName) != 0; i++);
	if (i < 3)
		std::cout << "Intern creates " << this->forms[i]->getName() << std::endl;
	return i < 3 ? this->forms[i]->clone(target) : throw Intern::FormNotFoundException();
}

const char *Intern::FormNotFoundException::what() const throw() {
	return ("Form type not found");
}