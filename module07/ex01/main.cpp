#include "iter.hpp"

int main() {
    // Test 1: Array of integers
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original integer array: ";
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;

    std::cout << "Incrementing integer array: ";
    iter(intArray, intLength, increment);
    iter(intArray, intLength, printElement<int>);
    std::cout << std::endl;

    // Test 2: Array of doubles
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    size_t doubleLength = sizeof(doubleArray) / sizeof(doubleArray[0]);

    std::cout << "Original double array: ";
    iter(doubleArray, doubleLength, printElement<double>);
    std::cout << std::endl;

    // Test 3: Array of strings
    std::string stringArray[] = {"apple", "banana", "cherry"};
    size_t stringLength = sizeof(stringArray) / sizeof(stringArray[0]);

    std::cout << "Original string array: ";
    iter(stringArray, stringLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}