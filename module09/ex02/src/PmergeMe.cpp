#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

void printVector(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << (i == vec.size() - 1 ? "\n" : " ");
	}
}
void printList(const std::list<int>& lst) {
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

PmergeMe::PmergeMe(std::string const &numbers) {
	std::string cpy = numbers;
	std::string result;
	size_t startPos = 0;
	while (getStringUntil(cpy, result, ' ', startPos)) {
		int num = std::atoi(result.c_str());
		this->vec.push_back(num);
		this->lst.push_back(num);
	}
	// printVector(this->vec);
	// printList(this->lst);
	// this->miSort(this->vec, 1);

	this->vectorSort();
}

PmergeMe::PmergeMe(PmergeMe const &src) {
	*this = src;
}

PmergeMe::~PmergeMe() {
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {
	this->vec = rhs.vec;
	this->lst = rhs.lst;
	return (*this);
}


void PmergeMe::vectorSort() {
	size_t const 	halfSize = this->vec.size() / 2;

	std::cout << halfSize << std::endl;
	std::vector<int> A, B;

	for (size_t i = 0; i < this->vec.size(); i += 2){
		if (i + 1 < this->vec.size()) {
			A.push_back(std::min(this->vec[i], this->vec[i + 1]));
			B.push_back(std::max(this->vec[i], this->vec[i + 1]));
		}
		else 
			A.push_back(this->vec[i]);
	}
	printVector(A);
	printVector(B);

}
void PmergeMe::listSort() {

}