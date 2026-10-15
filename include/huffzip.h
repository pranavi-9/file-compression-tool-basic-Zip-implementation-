// huffzip.h - shared interface for the File Compression Tool (Team 14)
// Everyone codes against these declarations. Change them only after the
// whole team agrees, because other people's code depends on them.
#pragma once

#include <array>
#include <cstdint>
#include <string>
#include <vector>

// Exit codes returned by the program (SAD 4.4 Error Handling)
enum ExitCode {
    EXIT_OK = 0,           // success
    EXIT_USAGE = 1,        // wrong command-line arguments
    EXIT_FILE_ERROR = 2,   // file missing, unreadable or not writable
    EXIT_FAILURE_OTHER = 3 // corrupted input, not implemented, etc.
};

// One count per possible byte value (0-255)
using FreqTable = std::array<std::uint64_t, 256>;

// ---------- REQ-1 (Pranavi, issue #1): input validation ----------
// Returns true if 'path' is an existing, readable regular file.
// On failure returns false and puts a human-readable reason in 'error'.
bool validate_input_file(const std::string& path, std::string& error);

// Reads the whole file in BINARY mode into 'out'.
// Returns false (and sets 'error') if the file cannot be read.
bool read_file_bytes(const std::string& path, std::vector<std::uint8_t>& out,
                     std::string& error);

// ---------- REQ-2 (Pranavi, issue #2): character frequencies ----------
// Counts how many times each byte value appears in 'data'.
FreqTable count_frequencies(const std::vector<std::uint8_t>& data);

// ---------- REQ-3..REQ-7 (Pavan, Inchara, Rachit) ----------
// Implemented in src/codec.cpp. Currently stubs that return
// EXIT_FAILURE_OTHER until the owners replace them.
int compress_file(const std::string& input_path, const std::string& output_path);
int decompress_file(const std::string& input_path, const std::string& output_path);
