#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdexcept>

// Génère l'ordre d'insertion basé sur les nombres de Jacobsthal
std::vector<size_t> generate_insertion_order(size_t m) {
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

// Implémentation pour conteneurs avec accès aléatoire (comme vector)
template<typename RandomIt>
void merge_insertion_sort(RandomIt first, RandomIt last) {
    if (last - first <= 1) return;

    typedef typename std::iterator_traits<RandomIt>::value_type T;
    std::vector<T> S, L;

    // Créer des paires et trier
    for (RandomIt it = first; it < last - 1; it += 2) {
        if (it[0] > it[1]) std::swap(it[0], it[1]);
        S.push_back(it[0]);
        L.push_back(it[1]);
    }

    // Gérer la taille impaire
    if ((last - first) % 2 != 0) S.push_back(*(last - 1));

    // Trier récursivement L
    merge_insertion_sort(L.begin(), L.end());

    // Générer l'ordre d'insertion et insérer
    std::vector<size_t> order = generate_insertion_order(S.size());
    for (std::vector<size_t>::iterator it_order = order.begin(); it_order != order.end(); ++it_order) {
        size_t idx = *it_order;
        typename std::vector<T>::iterator pos = std::lower_bound(L.begin(), L.end(), S[idx]);
        L.insert(pos, S[idx]);
    }

    // Copier le résultat trié
    std::copy(L.begin(), L.end(), first);
}

// Implémentation pour list (utilisation d'un vecteur temporaire)
template<typename T>
void merge_insertion_sort(std::list<T>& lst) {
    if (lst.size() <= 1) return;

    std::list<T> S, L;
    typename std::list<T>::iterator it = lst.begin();

    // Créer des paires et trier
    while (it != lst.end()) {
        typename std::list<T>::iterator a = it++;
        if (it == lst.end()) {
            S.splice(S.end(), lst, a);
            break;
        }
        typename std::list<T>::iterator b = it++;
        if (*a > *b) std::swap(*a, *b);
        S.splice(S.end(), lst, a);
        L.splice(L.end(), lst, b);
    }

    // Trier récursivement L
    merge_insertion_sort(L);

    // Convertir S en vector pour l'accès indexé
    std::vector<T> S_vec(S.begin(), S.end());
    std::vector<size_t> order = generate_insertion_order(S_vec.size());

    // Insérer les éléments dans L
    for (std::vector<size_t>::iterator it_order = order.begin(); it_order != order.end(); ++it_order) {
        size_t idx = *it_order;
        T elem = S_vec[idx];
        typename std::list<T>::iterator pos = L.begin();
        while (pos != L.end() && *pos < elem) ++pos;
        L.insert(pos, elem);
    }

    lst.swap(L);
}

// Fonction de wrapper pour vector
template<typename T>
void ford_johnson(std::vector<T>& vec) {
    merge_insertion_sort(vec.begin(), vec.end());
}

// Fonction de wrapper pour list
template<typename T>
void ford_johnson(std::list<T>& lst) {
    merge_insertion_sort(lst);
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

		std::string cpy = numbers;
		std::string result;
		std::vector<int> vec;
		size_t startPos = 0;
		while (getStringUntil(cpy, result, ' ', startPos)) {
			int num = std::atoi(result.c_str());
			vec.push_back(num);
		}

		merge_insertion_sort(vec.begin(), vec.end());
	
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
			std::cout << *it << " "; // 1 2 3 4 5 6
		}
	
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}