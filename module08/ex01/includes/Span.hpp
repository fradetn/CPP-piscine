#pragma once

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <limits.h>

class Span
{
private:
	std::vector<int> tab;
	unsigned int capacity;
public:
	Span();
	Span(unsigned int N);
	Span(Span const &src);
	~Span();

	Span & operator=(Span const & rhs);

	void showNumbers();
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	void addNumber(int number);
	int	shortestSpan();
	int longestSpan();

	class MaximumSpanCapacityException : public std::exception {
		const char* what() const throw() {
            return "Span has reach maximum capacity !";
        }
	};
	class NotEnoughtNumbersException : public std::exception {
		const char* what() const throw() {
            return "Not enought numbers to caculate a span !";
        }
	};
};
