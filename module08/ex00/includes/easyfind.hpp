#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm> // Pour std::find
#include <iterator>  // Pour les itérateurs
#include <exception> // Pour std::exception

class NotFoundException : public std::exception {
    const char *what() const throw() {
        return ("Element not found in the container!");
    }
};

template<typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw NotFoundException();
    }
    return (it);
}

#endif