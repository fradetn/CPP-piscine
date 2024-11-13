/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:10:26 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/13 14:28:37 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main( void ) {

    Bureaucrat bob = Bureaucrat("Bob", 1);
    Bureaucrat jim = Bureaucrat("Jim", 150);
    
    try {

        bob.incrementGrade();
        jim.decrementGrade();
    }
    catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    
    std::cout << bob << std::endl;
    std::cout << jim << std::endl;
    return 0;
}
