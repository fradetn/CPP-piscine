#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

template <typename T>
void printVector(const std::vector<T>& vec) {
	if (vec.size() == 0)
		std::cout << std::endl;
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << (i == vec.size() - 1 ? "\n" : " ");
	}
}

template <typename Iterator>
void printVector(Iterator begin, Iterator end) {
	if (end - begin <= 0)
		std::cout << std::endl;
	for (Iterator i = begin; i != end; ++i) {
		std::cout << *i << (i == end - 1 ? "\n" : " ");
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

	this->vectorSort(this->vec.begin(), this->vec.end(), 1);
	printVector(this->vec);
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

// Génère l'ordre d'insertion basé sur les nombres de Jacobsthal
std::vector<size_t> PmergeMe::generateInsertionOrder(size_t m) {
    if (m == 0) return std::vector<size_t>();
    std::vector<size_t> order(1, 0);
    if (m == 1) return order;

    std::vector<size_t> jacob(2, 0);
    jacob[1] = 1;
    while (jacob.back() < m) {
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
    }

    size_t prev = 1;
    size_t current_idx = 2;
    while (prev < m) {
        if (current_idx >= jacob.size()) {
            for (size_t i = m; i > prev; --i) order.push_back(i - 1);
            break;
        }

        size_t group_size = std::min(jacob[current_idx] - jacob[current_idx - 1], m - prev);
        for (size_t i = prev + group_size; i > prev; --i) {
            order.push_back(i - 1);
        }
        prev += group_size;
        current_idx++;
    }

    return order;
}

void PmergeMe::vectorSort(vecIt first, vecIt last) {
    if (last - first <= 1) return;

    std::vector<int> S, L;

    // Créer des paires et trier
    for (vecIt it = first; it < last - 1; it += 2) {
        if (it[0] > it[1]) std::swap(it[0], it[1]);
        S.push_back(it[0]);
        L.push_back(it[1]);
    }

    // Gérer la taille impaire
    if ((last - first) % 2 != 0) S.push_back(*(last - 1));

	std::cout << std::endl;
    // Trier récursivement L
    vectorSort(L.begin(), L.end());

    // Générer l'ordre d'insertion et insérer
    std::vector<size_t> order = this->generateInsertionOrder(S.size());
	printVector(order);
    for (std::vector<size_t>::iterator it_order = order.begin(); it_order != order.end(); ++it_order) {
        size_t idx = *it_order;
        std::vector<int>::iterator pos = std::lower_bound(L.begin(), L.end(), S[idx]);
        L.insert(pos, S[idx]);
    }

    // Copier le résultat trié
    std::copy(L.begin(), L.end(), first);
}

void PmergeMe::vectorSort(vecIt first, vecIt last, int recIdx) {
	std::cout << GREEN"Recursion Index : " << recIdx << DEFAULT << std::endl;
	std::cout << YELLOW"vector : " DEFAULT;
	printVector(first, last);
	std::cout << std::endl;

    if (last - first <= 1) return;

    std::vector<int> S, L;

    // Créer des paires et trier
    for (vecIt it = first; it < last - 1; it += 2) {
        if (it[0] > it[1]) std::swap(it[0], it[1]);
        S.push_back(it[0]);
        L.push_back(it[1]);

		std::cout << "S : ";
		printVector(S);
		std::cout << "L : ";
		printVector(L);
    }

    // Gérer la taille impaire
    if ((last - first) % 2 != 0) S.push_back(*(last - 1));

	std::cout << std::endl;
    // Trier récursivement L
    vectorSort(L.begin(), L.end(), recIdx + 1);
	std::cout << RED"Recursion End : " << recIdx << DEFAULT << std::endl;
	std::cout << YELLOW"S : " DEFAULT;
	printVector(S);
	std::cout << YELLOW"L : " DEFAULT;
	printVector(L);

	std::cout << std::endl;

    // Générer l'ordre d'insertion et insérer
    std::vector<size_t> order = this->generateInsertionOrder(S.size());
	std::cout << MAGENTA"insertion order : " DEFAULT;
	printVector(order);
	std::cout << "S : ";
	printVector(S);
    for (std::vector<size_t>::iterator it_order = order.begin(); it_order != order.end(); ++it_order) {
        size_t idx = *it_order;
        std::vector<int>::iterator pos = std::lower_bound(L.begin(), L.end(), S[idx]);
		std::cout << "idx : " << idx << std::endl;
		std::cout << "inserting : " << S[idx] << " at pos :" << std::distance(L.begin(), pos) << std::endl;
        L.insert(pos, S[idx]);
		// std::cout << "pos : " << *pos << std::endl;
		std::cout << "L : ";
		printVector(L);
    }

    // Copier le résultat trié
    std::copy(L.begin(), L.end(), first);
	std::cout << std::endl;
}

void PmergeMe::listSort() {

}