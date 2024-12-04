/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfradet <nfradet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:45:25 by nfradet           #+#    #+#             */
/*   Updated: 2024/12/04 15:06:13 by nfradet          ###   ########.fr       */
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

	void vectorSort();
	void listSort();

	template <typename T> 
	void miSort(T& container, int pairLevel);
};

bool getStringUntil(const std::string& input, std::string& result, char delimiter, size_t& startPos);

template <typename T>
T next(T it, int step) {
	std::advance(it, step);
	return (it);
}
		
template <typename T>
void PmergeMe::miSort(T& container, int pairLevel) {
	typedef typename T::iterator Iterator;

	// Le nombre de pairs possible
	int pairNbr = container.size() / pairLevel;

	//condition d'arret de la recursion
	if (pairNbr < 2)
		return;

	bool isOdd = pairNbr % 2 == 1;

	Iterator start = container.begin();
	Iterator last = next(start, pairLevel * pairNbr);
    Iterator end = next(last, -(isOdd * pairLevel));

	std::cout << *start << " -> " << *last << " -> " << *end << std::endl;
}
