#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template< typename T, typename F >
void iter(T *array, size_t length, F func){
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}


// Sample function to use with iter
template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

// Another sample function to modify elements
void increment(int& element) {
    element += 1;
}

#endif