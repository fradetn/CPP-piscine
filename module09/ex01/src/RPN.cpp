/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:45:23 by nfradet           #+#    #+#             */
/*   Updated: 2024/12/02 21:57:40 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() : rpnStr(NULL){
}

RPN::RPN(RPN const &src) : rpnStr(src.rpnStr) {
}

RPN::RPN(std::string const &str) : rpnStr(str) {
}

RPN::~RPN() {
}

RPN &RPN::operator=(RPN const &rhs) {
	(void) rhs;
	// this->rpnStr = rhs.rpnStr;
	// rhs.rpnStr.copy(this->rpnStr.c_str(), rhs.rpnStr.size(), 0);
	return (*this);
}

void RPN::calculateExpression() {
	std::stack<int> stack;
	std::string result;
	size_t startPos = 0;
	
	while (getStringUntil(this->rpnStr, result, ' ', startPos)) {
		if (isOperator(result)) {
			if (stack.size() < 2)
				throw std::runtime_error("Error: invalid RPN expression (not enought operands).");
			int b = stack.top(); stack.pop();
			int a = stack.top(); stack.pop();

			if (result.compare("+") == 0)
				stack.push(a + b);
			else if (result.compare("-") == 0)
				stack.push(a - b);
			else if (result.compare("*") == 0)
				stack.push(a * b);
			else if (result.compare("/") == 0) {
				if (b == 0)
					throw std::runtime_error("Error: division by zero.");
				stack.push(a / b);
			}
		}
		else {
			stack.push(std::atoi(result.c_str()));
		}
	}
	if (stack.size() != 1)
		throw std::runtime_error("Error: invalid RPN expression (too many operands).");
	std::cout << stack.top() << std::endl;
}
