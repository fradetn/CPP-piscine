/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:59:42 by nfradet           #+#    #+#             */
/*   Updated: 2024/12/17 15:07:24 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>
#include <cstdlib>

Base *generate(void) {
	int randNum = (std::rand() % 3) + 1;
	if (randNum == 1) {
		std::cout << "A generated" << std::endl;
		return (new A());
	}
	else if (randNum == 2) {
		std::cout << "B generated" << std::endl;
		return (new B());
	}
	else {
		std::cout << "C generated" << std::endl;
		return (new C());
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void) a;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << " Not A" << std::endl;
	}
	try {
		B &b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void) b;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << " Not B" << std::endl;
	}
	try {
		C &c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void) c;
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << " Not C" << std::endl;
	}
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));
	Base *randomClass = generate();
	std::cout << std::endl << "----------identify with pointer----------" << std::endl;
	identify(randomClass);
	std::cout << std::endl << "----------identify with reference----------" << std::endl;
	identify(*randomClass);
	delete randomClass;
	return (0);
}