#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        // Test avec std::vector
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        std::cout << "Testing with std::vector:" << std::endl;
        std::vector<int>::iterator itVec = easyfind(vec, 4);
        std::cout << "Found: " << *itVec << std::endl;

        // Test avec un élément non présent
        std::cout << "Looking for 100 in std::vector:" << std::endl;
        itVec = easyfind(vec, 100);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        // Test avec std::list
        std::list<int> lst;
        lst.push_back(1);
        lst.push_back(2);
        lst.push_back(3);
        lst.push_back(4);
        std::cout << "\nTesting with std::list:" << std::endl;
        std::list<int>::iterator itList = easyfind(lst, 1);
        std::cout << "Found: " << *itList << std::endl;

        // Test avec un élément non présent
        std::cout << "Looking for 50 in std::list:" << std::endl;
        itList = easyfind(lst, 50);

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}