#pragma once

#include <string>

class AForm;

class Intern
{
private:
	AForm *forms[3];
public:
	Intern(void);
	Intern(Intern const &src);
	~Intern();

	Intern & operator=(Intern const & rhs);

	AForm *makeForm(std::string formName, std::string target);

	class FormNotFoundException : public std::exception {
	public:
		virtual const char *what() const throw();
	};
};
