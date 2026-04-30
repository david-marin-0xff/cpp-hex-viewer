#pragma once

#include <string>

class CLI
{
public:
    CLI(int argc, char* argv[]);

    void printHelp() const;

    bool showHelp() const;

    const std::string& filename() const;

    std::size_t bytesPerLine() const;

    bool useColor() const;

    bool uppercaseHex() const;

private:
    std::string m_filename;

    std::size_t m_bytesPerLine = 16;

    bool m_help = false;

    bool m_useColor = true;

    bool m_uppercase = false;
};