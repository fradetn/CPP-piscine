/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:45:25 by nfradet           #+#    #+#             */
/*   Updated: 2024/12/02 19:53:14 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <stack>
#include <cstdlib>

// #define M_SIGN(c) (c == "/" || c == "*" || c == "+" || c == "-")

class RPN
{
private:
	std::string const rpnStr;
	
public:
	RPN();
	RPN(std::string const &str);
	RPN(RPN const &src);
	~RPN();

	RPN &operator=(RPN const &rhs);

	void calculateExpression();
};


bool getStringUntil(const std::string& input, std::string& result, char delimiter, size_t& startPos);
bool isOperator(std::string const &str);