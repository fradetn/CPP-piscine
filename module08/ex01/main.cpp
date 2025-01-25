/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:56:16 by nfradet           #+#    #+#             */
/*   Updated: 2025/01/26 00:56:57 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>

int main() {
	Span span = Span(5);
	int longestSpan;
	int shortestSpan;
	
	std::srand((unsigned)std::time(0));

	try {
		span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);

	}
	catch (std::exception &e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}
	span.showNumbers();
	longestSpan = span.longestSpan();
	std::cout << "Longest span : " << longestSpan << std::endl;
	shortestSpan = span.shortestSpan();
	std::cout << "Shortest span : " << shortestSpan << std::endl;
	std::cout << std::endl;

	//Test avec une plage d'iterateurs
	Span iterSpan = Span(100);
	
	try {
        std::vector<int> numbers;
        for (int i = 0; i < 1000; ++i) {
            numbers.push_back(rand() % 100);
        }
		iterSpan.addNumber(numbers.begin(), numbers.end());
		
	}
	catch(std::exception &e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}
	iterSpan.showNumbers();
	longestSpan = iterSpan.longestSpan();
	std::cout << "Longest span (range iter test): " << longestSpan << std::endl;
	shortestSpan = iterSpan.shortestSpan();
	std::cout << "Shortest span (range iter test): " << shortestSpan << std::endl;
	std::cout << std::endl;
	
	// Test avec une plage de 10 000 nombres
	Span largeSpan(10000);
	std::vector<int> largeNumbers(10000);
	std::generate(largeNumbers.begin(), largeNumbers.end(), rand); // Génère des valeurs aléatoires

	try {
		largeSpan.addNumber(largeNumbers.begin(), largeNumbers.end());
		std::cout << "Shortest span (large test): " << largeSpan.shortestSpan() << std::endl;
		std::cout << "Longest span (large test): " << largeSpan.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Exception : " << e.what() << std::endl;
	}
	// largeSpan.showNumbers();
}