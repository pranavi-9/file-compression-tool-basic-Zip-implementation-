
#include "huffman.hpp"

#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    using namespace huffman;

    // Test 1: Empty input frequencies
    std::array<std::uint64_t, BYTE_VALUES> frequencies{};
    auto empty_tree = build_tree(frequencies);
    assert(empty_tree == nullptr);

    // Test 2: One repeated byte
    frequencies[static_cast<unsigned char>('A')] = 5;
    auto single_tree = build_tree(frequencies);
    auto single_codes = generate_codes(single_tree);

    assert(single_tree != nullptr);
    assert(single_codes[static_cast<unsigned char>('A')] == "0");

    std::vector<std::uint8_t> repeated(5, 'A');
    auto single_encoded = encode(repeated, single_codes);

    assert(single_encoded.bit_count == 5);
    assert(single_encoded.bytes.size() == 1);
    assert(single_encoded.bytes[0] == 0);

    // Test 3: Multiple byte values
    frequencies = {};
    frequencies['A'] = 5;
    frequencies['B'] = 2;
    frequencies['C'] = 1;
    frequencies['D'] = 1;

    auto tree = build_tree(frequencies);
    auto codes = generate_codes(tree);

    assert(tree != nullptr);
    assert(!codes['A'].empty());
    assert(!codes['B'].empty());
    assert(!codes['C'].empty());
    assert(!codes['D'].empty());

    // Test 4: Encode a sample input
    std::vector<std::uint8_t> input = {'A', 'B', 'C', 'D', 'A'};
    auto encoded = encode(input, codes);

    assert(encoded.bit_count > 0);
    assert(encoded.bytes.size() == (encoded.bit_count + 7) / 8);

    std::cout << "All Huffman tests passed!\n";
    return 0;
}
