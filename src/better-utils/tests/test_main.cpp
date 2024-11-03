#include "test_binary_search_tree.h"
#include "test_array_utils.h"

#include <iostream>

static void printTestStart() {
    std::cout << "Tests start." << std::endl;
}

static void printTestEnd() {
    std::cout << "Test end." << std::endl;
}

int main() {
    printTestStart();

    test_binary_search_tree();
    test_array_utils();

    printTestEnd();
}