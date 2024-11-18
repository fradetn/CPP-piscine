/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:10:26 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/18 19:30:16 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void ) {

    Bureaucrat bob = Bureaucrat("Bob", 31);
    Bureaucrat jim = Bureaucrat("Jim", 7);
	Form registerForm = Form("Register", 30, 8);
    
    std::cout << registerForm << std::endl;
    try {
		bob.signForm(registerForm);
		bob.incrementGrade();
		bob.signForm(registerForm);
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

	
    std::cout << registerForm << std::endl;
    // std::cout << jim << std::endl;
    return 0;
}
