/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:10:26 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/20 16:15:54 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main( void ) {

    Bureaucrat bob = Bureaucrat("Bob", 1);
    Bureaucrat jim = Bureaucrat("Jim", 7);
    ShrubberyCreationForm home("home");
    RobotomyRequestForm robot("jean");
    PresidentialPardonForm pardon("poutine");

	jim.signForm(robot);
	jim.signForm(home);
	jim.executeForm(robot);
	jim.signForm(pardon);
	jim.executeForm(pardon);

    try {
		// bob.signForm(pardon);
        pardon.execute(bob);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    
    // try {
    //     home.execute(bob);
    // }
    // catch (std::exception & e) {
    //     std::cerr << e.what() << std::endl;
    // }

    std::cout << home << std::endl;
    std::cout << robot << std::endl;
    std::cout << jim << std::endl;
    return 0;
}
