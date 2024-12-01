/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:34:46 by nfradet           #+#    #+#             */
/*   Updated: 2024/12/01 12:18:29 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* -------------------------------------------------------------------------- */
/*                          Constructors & operators                          */
/* -------------------------------------------------------------------------- */

Span::Span() : capacity(0) {}

Span::Span(unsigned int N) : capacity(N) {}

Span::Span(Span const &src) : capacity(src.capacity) {}

Span::~Span() {}

Span & Span::operator=(Span const & rhs) {
	(void) rhs;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                              Members functions                             */
/* -------------------------------------------------------------------------- */

void Span::addNumber(int number) {
	if (this->tab.size() >= this->capacity || this->tab.size() >= this->tab.max_size())
		throw MaximumSpanCapacityException();
	else
		this->tab.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
		size_t range = std::distance(begin, end);

		if (this->tab.size() + range > this->capacity)
			throw MaximumSpanCapacityException();
		this->tab.insert(this->tab.end(), begin, end);
}

int	Span::shortestSpan() {
	if (this->tab.size() < 2)
		throw MaximumSpanCapacityException();
	std::vector<int> sortedNumbers = tab;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	
	int min = INT_MAX;
	for (size_t i = 1; i < sortedNumbers.size(); i++) {
		int tmp = sortedNumbers[i] - sortedNumbers[i - 1];
		if (tmp < min)
			min = tmp;
	}
	return (min);
}
int Span::longestSpan(){
	if (this->tab.size() < 2)
		throw NotEnoughtNumbersException();
	else {
		int min = *std::min_element(this->tab.begin(), this->tab.end());
		int max = *std::max_element(this->tab.begin(), this->tab.end());
		return (max - min);
	}
	return (-1);	
}

void affInt(int i) {
	std::cout << i << ", ";
}

void Span::showNumbers() {
	std::cout << "Numbers of span (max capacity: " << this->capacity << ") :" << std::endl;
	if (this->tab.size() < 1)
		std::cout << "No number added";
	else
		for_each(this->tab.begin(), this->tab.end(), affInt);
	std::cout << std::endl;
}
