// ===== Standard library includes =====

// Input / output streams (std::cout, std::cerr)
#include <iostream>

// File stream for reading files
#include <fstream>

// Formatting helpers (std::hex, std::setw, std::setfill)
#include <iomanip>

// Dynamic array with automatic memory management (RAII)
#include <vector>

// std::string and string utilities
#include <string>

// Character classification (std::isprint)
#include <cctype>

// C-style string comparison (std::strcmp)
#include <cstring>

// ===== ANSI color escape codes =====
// These work in modern Windows terminals (Windows 10+)

#define CLR_RESET  "\x1b[0m"   // Reset all colors
#define CLR_OFFSET "\x1b[36m"  // Cyan for offsets
#define CLR_HEX    "\x1b[33m"  // Yellow for hex bytes
#define CLR_ASCII  "\x1b[32m"  // Green for ASCII view


// ===== Helper function =====
// Prints usage information and exits cleanly
void print_help()
{
    std::cout <<
        "hexview - simple console hex viewer\n\n"
        "Usage:\n"
        "  hexview [options] <file>\n\n"
        "Options:\n"
        "  -n <bytes>   Bytes per line (default: 16)\n"
        "  -h, --help   Show this help\n";
}


// ===== Program entry point =====
// argc = argument count
// argv = argument values (array of C-style strings)
int main(int argc, char* argv[])
{
    // If no arguments were provided, show help
    if (argc < 2)
    {
        print_help();
        return 1;
    }

    // Number of bytes to show per line (default = 16)
    std::size_t bytesPerLine = 16;

    // File name to open (empty until parsed)
    std::string filename;

    // ===== Command-line argument parsing =====
    for (int i = 1; i < argc; ++i)
    {
        // Help flag
        if (std::strcmp(argv[i], "-h") == 0 ||
            std::strcmp(argv[i], "--help") == 0)
        {
            print_help();
            return 0;
        }
        // Bytes-per-line flag
        else if (std::strcmp(argv[i], "-n") == 0)
        {
            // Make sure a number follows -n
            if (i + 1 >= argc)
            {
                std::cerr << "Error: -n requires a number\n";
                return 1;
            }

            // Convert string to unsigned long
            bytesPerLine = std::stoul(argv[++i]);
        }
        else
        {
            // Any non-flag argument is treated as filename
            filename = argv[i];
        }
    }

    // If no filename was found, error out
    if (filename.empty())
    {
        std::cerr << "Error: no file specified\n";
        return 1;
    }

    // ===== Open file in binary mode =====
    std::ifstream file(filename, std::ios::binary);

    // Check if file opened successfully
    if (!file)
    {
        std::cerr << "Error: could not open file: " << filename << "\n";
        return 1;
    }

    // ===== Buffer for reading bytes =====
    // std::vector automatically manages memory (RAII)
    std::vector<unsigned char> buffer(bytesPerLine);

    // Offset counter (position in file)
    std::size_t offset = 0;

    // ===== Main read loop =====
    // Read bytesPerLine bytes at a time
    while (
        file.read(reinterpret_cast<char*>(buffer.data()), buffer.size()) ||
        file.gcount() > 0
    )
    {
        // Actual number of bytes read
        std::size_t count = file.gcount();

        // ----- Print offset -----
        std::cout
            << CLR_OFFSET
            << std::setw(8)
            << std::setfill('0')
            << std::hex
            << offset
            << CLR_RESET
            << "  ";

        // ----- Print hex bytes -----
        std::cout << CLR_HEX;

        for (std::size_t i = 0; i < bytesPerLine; ++i)
        {
            if (i < count)
            {
                // Print byte as two-digit hex
                std::cout
                    << std::setw(2)
                    << static_cast<int>(buffer[i])
                    << " ";
            }
            else
            {
                // Pad if fewer bytes than bytesPerLine
                std::cout << "   ";
            }
        }

        std::cout << CLR_RESET;

        // ----- Print ASCII representation -----
        std::cout << " " << CLR_ASCII << "|";

        for (std::size_t i = 0; i < count; ++i)
        {
            unsigned char c = buffer[i];

            // Print character if printable, otherwise '.'
            std::cout << (std::isprint(c) ? static_cast<char>(c) : '.');
        }

        std::cout << "|" << CLR_RESET << "\n";

        // Advance offset by number of bytes processed
        offset += count;
    }

    // Successful execution
    return 0;
}
