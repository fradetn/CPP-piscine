/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:10:26 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/13 20:42:11 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main( void ) {

    Bureaucrat bob = Bureaucrat("Bob", 2);
    Bureaucrat jim = Bureaucrat("Jim", 150);
    
    try {
        bob.decrementGrade();
        jim.decrementGrade();
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
	
    std::cout << bob << std::endl;
    std::cout << jim << std::endl;
    return 0;
}
