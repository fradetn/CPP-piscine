/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:01:40 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/19 18:26:57 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"

class AForm
{

private:
	 std::string const name;
	 bool isSigned;
	 int const signRequired;
	 int const execRequired;

public:
	AForm(void);
	AForm(std::string _name, int signReq, int execReq);
	AForm(AForm const &src);
	virtual ~AForm();
	
	AForm & operator=(AForm const & rhs);
	std::string const & getName(void) const;
	bool getIsSigned(void) const;
	int const & getSignRequired(void) const;
	int const & getExecRequired(void) const;

	virtual void executeAction() const = 0;

	void execute(Bureaucrat const &executor) const;
	
	void beSigned(Bureaucrat const &bur);

	class GradeTooHighException : public std::exception {
	public :
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public :
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception {
	public :
		virtual const char *what() const throw();
	};
	class FormAlreadySignedException : public std::exception {
	public :
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, AForm const & obj);
