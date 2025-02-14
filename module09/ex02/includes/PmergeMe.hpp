/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:45:25 by nfradet           #+#    #+#             */
/*   Updated: 2025/02/14 17:12:43 by nfradet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <stdexcept>

# define DEFAULT	"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"

typedef std::vector<int>::iterator	vecIt;

class PmergeMe
{
private:
	std::vector<int> vec;
	std::list<int> lst;
public:
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	PmergeMe(std::string const &numbers);
	~PmergeMe();

	PmergeMe &operator=(PmergeMe const &rhs);

	void vectorSort(vecIt first, vecIt last);
	void vectorSort(vecIt begin, vecIt end, int recIdx);
	void listSort();

	std::vector<size_t> generateInsertionOrder(size_t m);
};

bool getStringUntil(const std::string& input, std::string& result, char delimiter, size_t& startPos);
