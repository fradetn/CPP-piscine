/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:55:42 by nfradet           #+#    #+#             */
/*   Updated: 2024/12/02 20:03:46 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isOperator(std::string const &str) {
	if (str == "+" || str == "-" || str == "*" ||str == "/")
		return true;
	return false;
}

bool getStringUntil(const std::string& input, std::string& result, char delimiter, size_t& startPos) {
	size_t delimPos = input.find(delimiter, startPos);

	if (startPos == std::string::npos)
		return false;

	if (delimPos == std::string::npos) {
		result = input.substr(startPos);
		startPos = std::string::npos;
		return (true);
	}
	result = input.substr(startPos, delimPos - startPos);
	startPos = delimPos + 1;
	return (true);
}

bool	isAllDigit(std::string const &str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (std::isdigit(str[i]) == 0)
			return (false);
	}
	return (true);
}

void checkInput(int argc, char **argv) {
	if (argc != 2)
		throw std::runtime_error("Error");
	std::string testRPN = argv[1];
	std::string result;
	size_t startPos = 0;
	while (getStringUntil(testRPN, result, ' ', startPos)) {
		if (result.empty() == true || ( !isOperator(result) && !isAllDigit(result)))
			throw std::runtime_error("Error");
	}
}

int main(int argc, char **argv) {
	

	try {
		checkInput(argc, argv);
		RPN exp = RPN(argv[1]);
		exp.calculateExpression();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}