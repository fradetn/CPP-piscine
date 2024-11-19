/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 14:58:46 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/18 19:25:09 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdexcept>
#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
private:
	std::string const name;
	int	grade;

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();

	std::string const getName(void) const;
	int getGrade(void) const;

	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(Form &form);

	Bureaucrat & operator=(Bureaucrat const & rhs);

	class GradeTooHighException : public std::exception {
	public :
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public :
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, Bureaucrat const & obj);