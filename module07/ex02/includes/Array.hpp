#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <cstdlib>

template<typename T = int>
class Array {
private :
    T *array;
    unsigned int n;
public :
    Array() : n(0), array(NULL){}

    Array(unsigned int _n) {
        this->array = new T[_n];
        this->n = _n;
    }

    Array(Array const & src) : array(NULL), n(src.n){
        if (n > 0) {
            array = new T[n];
            for (unsigned int i = 0; i < n; i++)
                array[i] = src.array[i];
        }
    }

    ~Array() {
        delete [] this->array;
    }

    Array &operator=(const Array &rhs) {
        if (this != &rhs) {
            // Deallocate current memory
            if (this->array != NULL)
                delete[] this->array;

            // Copy new size and allocate memory
            n = rhs.n;
            this->array = (n > 0) ? new T[n] : NULL;

            // Copy elements
            for (unsigned int i = 0; i < n; i++) {
                this->array[i] = rhs.array[i];
            }
        }
        return *this;
    }


    T &operator[](unsigned int index) {
        if (index >= this->n) {
            throw std::out_of_range("Index out of bounds");
        }
        return this->array[index];
    }
};

#endif