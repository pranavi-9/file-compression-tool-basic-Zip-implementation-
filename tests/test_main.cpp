
#include "huffzip.h"
#include "huffman.hpp"

#include <iostream>

// Implemented in tests/test_huffman.cpp
void run_huffman_tests();

int main() {
    std::cout << "Running project tests...\n";

    run_huffman_tests();

    std::cout << "All tests passed\n";
    return 0;
}
