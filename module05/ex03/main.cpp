/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:10:26 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/20 16:26:02 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

int main( void ) {

    Bureaucrat bob = Bureaucrat("Bob", 1);
    Bureaucrat jim = Bureaucrat("Jim", 7);
	Intern kevin = Intern();
	AForm * form = new ShrubberyCreationForm("test");

	try {
		form = kevin.makeForm("presidential pardon", "Bob");
		std::cout << *form << std::endl;
		delete form;
		kevin.makeForm("shrubbery creation", "Jim");
		std::cout << *form << std::endl;
		kevin.makeForm("fake form", "Bob");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
}
