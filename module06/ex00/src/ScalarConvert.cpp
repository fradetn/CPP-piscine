/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvert.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:53:14 by nfradet           #+#    #+#             */
/*   Updated: 2024/11/24 20:51:50 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvert.hpp"
#include <iomanip>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>

#define CHAR	1
#define INT		2
#define FLOAT	3
#define DOUBLE	4
#define UNKNOWN	5

ScalarConvert::ScalarConvert() {}

ScalarConvert::ScalarConvert(ScalarConvert const & src) {
	*this = src;
}

ScalarConvert::~ScalarConvert() {}

ScalarConvert &ScalarConvert::operator=(ScalarConvert const &rhs) {
	(void) rhs;
	return (*this);
}

bool	isAllDigit(std::string const &str) {
	for (size_t i = 0; i < str.size(); i++) {
		if (std::isdigit(str[i]) == 0)
			return (false);
	}
	return (true);
}

int detectType(std::string const &str) {
	if (str.size() == 1 && !std::isdigit(str[0]))
		return (CHAR);
	else if (str == "+inf" || str == "-inf" || str == "nan")
		return (DOUBLE);
	else if (str == "+inff" || str == "-inff" || str == "nanf")
		return (FLOAT);
	else if (str.find('.') != std::string::npos) {
		if (str[str.size() - 1] == 'f')
			return (FLOAT);
		else
			return (DOUBLE);
	}
	if ((str[0] == '-' || str[0] == '+' || isdigit(str[0])) && isAllDigit(&str[1]))
		return (INT);
	return (UNKNOWN);
}

void displayResult(char c, int i, float f, double d, long long limitCheck) {
	if (c == '\0')
		std::cout << "char: Non dissplayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
	if (limitCheck > 2147483647 || limitCheck < -2147483648)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
	if (limitCheck > __FLT_MAX__)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
	if (limitCheck > __DBL_MAX__)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

void ScalarConvert::convert(std::string const &str) {
	int type;
	std::string toChar;
	int toInt;
	long long toIntLong;
	float toFloat;
	double toDouble;

	type = detectType(str);
	// Char convert
	if (type == CHAR) {
		toChar = str[0];
		displayResult(toChar[0], static_cast<int>(toChar[0]), static_cast<float>(toChar[0]), static_cast<double>(toChar[0]), 0);
		return;
	}

	// Int convert
	if (type == INT) {
		toIntLong = std::atoll(str.c_str());
		toInt = std::atol(str.c_str());

		toChar = (toInt >= 32 && toInt <= 126) ? static_cast<char>(toInt) : '\0';

		displayResult(toChar[0], toInt, static_cast<float>(toIntLong), static_cast<double>(toIntLong), toIntLong);
		return;
	}

	// Float  & Double convert
	if (type == FLOAT || type == DOUBLE) {
		if (str == "+inf" || str == "-inf" || str == "nan" || str == "+inff" || str == "-inff" || str == "nanf")
			toIntLong = 21474836470;
		else
			toIntLong = atoll(str.c_str());
		toDouble = std::strtod(str.c_str(), NULL);
		toChar = (toDouble >= 32 && toDouble <= 126) ? static_cast<char>(toDouble) : '\0';
		toFloat = std::strtof(str.c_str(), NULL);
		toInt = std::atoi(str.c_str());

		displayResult(toChar[0], toInt, toFloat, toDouble, toIntLong);
		return;
	}
}
