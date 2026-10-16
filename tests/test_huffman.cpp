
#include "huffman.hpp"

#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

namespace {

void test_empty_frequencies() {
    std::array<std::uint64_t, huffman::BYTE_VALUES> frequencies{};
    auto root = huffman::build_tree(frequencies);

    assert(root == nullptr);

    const auto codes = huffman::generate_codes(root);
    for (const auto& code : codes) {
        assert(code.empty());
    }
}

void test_single_symbol_repeated() {
    std::array<std::uint64_t, huffman::BYTE_VALUES> frequencies{};
    frequencies[static_cast<unsigned char>('A')] = 5;

    auto root = huffman::build_tree(frequencies);
    assert(root != nullptr);
    assert(root->is_leaf);

    const auto codes = huffman::generate_codes(root);
    assert(codes[static_cast<unsigned char>('A')] == "0");

    const std::vector<std::uint8_t> input(5, 'A');
    const auto encoded = huffman::encode(input, codes);

    assert(encoded.bit_count == 5);
    assert(encoded.bytes.size() == 1);
    assert(encoded.bytes[0] == 0);
}

void test_multiple_symbols_and_encoding() {
    std::array<std::uint64_t, huffman::BYTE_VALUES> frequencies{};
    frequencies[static_cast<unsigned char>('A')] = 5;
    frequencies[static_cast<unsigned char>('B')] = 2;
    frequencies[static_cast<unsigned char>('C')] = 1;

    auto root = huffman::build_tree(frequencies);
    assert(root != nullptr);

    const auto codes = huffman::generate_codes(root);

    assert(!codes[static_cast<unsigned char>('A')].empty());
    assert(!codes[static_cast<unsigned char>('B')].empty());
    assert(!codes[static_cast<unsigned char>('C')].empty());

    const std::vector<std::uint8_t> input = {'A', 'B', 'C', 'A'};
    const auto encoded = huffman::encode(input, codes);

    assert(encoded.bit_count > 0);
    assert(encoded.bytes.size() == (encoded.bit_count + 7) / 8);
}

} // namespace

// Called by the shared project test runner.
void run_huffman_tests() {
    test_empty_frequencies();
    test_single_symbol_repeated();
    test_multiple_symbols_and_encoding();

    std::cout << "[PASS] Huffman tests\n";
}
