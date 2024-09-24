/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:03:24 by nfradet           #+#    #+#             */
/*   Updated: 2024/09/24 12:04:09 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "includes/Fixed.hpp"
#include "includes/Point.hpp"

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);
    
    Point inside(5, 5);   // Point à l'intérieur du triangle
    Point outside(15, 5); // Point à l'extérieur du triangle
    Point onEdge(5, 0);   // Point sur une arrête du triangle

    std::cout << "Point inside: " << (bsp(a, b, c, inside) ? "True" : "False") << std::endl;
    std::cout << "Point outside: " << (bsp(a, b, c, outside) ? "True" : "False") << std::endl;
    std::cout << "Point on edge: " << (bsp(a, b, c, onEdge) ? "True" : "False") << std::endl;

    return 0;
}