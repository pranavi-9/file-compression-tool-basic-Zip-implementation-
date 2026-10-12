// codec.cpp - compression and decompression (REQ-3 to REQ-7)
// PLACEHOLDER: Pavan (REQ-3), Inchara (REQ-4, REQ-7) and Rachit (REQ-5, REQ-6)
// replace these stubs with the real implementation in Sprint 1.
#include "huffzip.h"

#include <iostream>

int compress_file(const std::string& input_path, const std::string& output_path) {
    (void)input_path;
    (void)output_path;
    std::cerr << "Error: compression is not implemented yet\n";
    return EXIT_FAILURE_OTHER;
}

int decompress_file(const std::string& input_path, const std::string& output_path) {
    (void)input_path;
    (void)output_path;
    std::cerr << "Error: decompression is not implemented yet\n";
    return EXIT_FAILURE_OTHER;
}
