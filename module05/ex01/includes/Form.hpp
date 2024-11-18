/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 01:01:40 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/18 19:06:58 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Form
{

private:
	 std::string const name;
	 bool isSigned;
	 int const signRequired;
	 int const execRequired;

public:
	Form(void);
	Form(std::string _name, int signReq, int execReq);
	Form(Form const &src);
	~Form();
	
	Form & operator=(Form const & rhs);
	std::string const & getName(void) const;
	bool getIsSigned(void) const;
	int const & getSignRequired(void) const;
	int const & getExecRequired(void) const;

	
	void beSigned(Bureaucrat const &bur);

	class GradeTooHighException : public std::exception {
	public :
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
	public :
		virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream &os, Form const & obj);
