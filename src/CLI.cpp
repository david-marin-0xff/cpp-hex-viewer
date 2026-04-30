#include "CLI.hpp"

#include <iostream>
#include <cstring>
#include <stdexcept>

CLI::CLI(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        if (std::strcmp(argv[i], "-h") == 0 ||
            std::strcmp(argv[i], "--help") == 0)
        {
            m_help = true;
        }
        else if (std::strcmp(argv[i], "-n") == 0)
        {
            if (i + 1 >= argc)
            {
                throw std::runtime_error("-n requires a value");
            }

            try
            {
                m_bytesPerLine = std::stoul(argv[++i]);

                if (m_bytesPerLine == 0)
                {
                    throw std::runtime_error("Invalid bytes per line");
                }
            }
            catch (...)
            {
                throw std::runtime_error("Invalid number for -n");
            }
        }
        else if (std::strcmp(argv[i], "--no-color") == 0)
        {
            m_useColor = false;
        }
        else if (std::strcmp(argv[i], "--uppercase") == 0)
        {
            m_uppercase = true;
        }
        else
        {
            m_filename = argv[i];
        }
    }

    if (!m_help && m_filename.empty())
    {
        throw std::runtime_error("No input file specified");
    }
}

void CLI::printHelp() const
{
    std::cout <<
        "hexview - modern C++ hex viewer\n\n"
        "Usage:\n"
        "  hexview [options] <file>\n\n"
        "Options:\n"
        "  -n <bytes>      Bytes per line\n"
        "  --uppercase     Uppercase hex output\n"
        "  --no-color      Disable ANSI colors\n"
        "  -h --help       Show help\n";
}

bool CLI::showHelp() const
{
    return m_help;
}

const std::string& CLI::filename() const
{
    return m_filename;
}

std::size_t CLI::bytesPerLine() const
{
    return m_bytesPerLine;
}

bool CLI::useColor() const
{
    return m_useColor;
}

bool CLI::uppercaseHex() const
{
    return m_uppercase;
}