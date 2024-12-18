/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:55:42 by nfradet           #+#    #+#             */
/*   Updated: 2024/12/03 16:09:15 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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

std::string checkInput(int argc, char **argv) {
	std::string str;
	if (argc < 2)
		throw std::runtime_error("Error");

	if (argc == 2) {
		str = argv[1];
		std::string result;
		size_t startPos = 0;
		while (getStringUntil(str, result, ' ', startPos)) {
			if (result.empty() == true || !isAllDigit(result))
				throw std::runtime_error("Error");
		}
		return (argv[1]);
	}
	else {
		for (int i = 1; i < argc; i++) {
			if (!isAllDigit(argv[i]))
				throw std::runtime_error("Error");
			str.append(argv[i]);
			str.append(" ");
		}
		str.erase(str.length() - 1);
		return (str);
	}
}

int main(int argc, char **argv) {
	std::string numbers;
	try {
		numbers = checkInput(argc, argv);
		// std::cout << "'" << numbers << "'" << std::endl;
		PmergeMe miSort = PmergeMe(numbers);
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}