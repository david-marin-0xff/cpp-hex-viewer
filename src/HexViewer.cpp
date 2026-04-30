#include "HexViewer.hpp"

#include <filesystem>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <stdexcept>

namespace
{
    constexpr const char* CLR_RESET  = "\x1b[0m";
    constexpr const char* CLR_OFFSET = "\x1b[36m";
    constexpr const char* CLR_HEX    = "\x1b[33m";
    constexpr const char* CLR_ASCII  = "\x1b[32m";
}

HexViewer::HexViewer(const CLI& cli)
    : m_cli(cli)
{
    if (!std::filesystem::exists(m_cli.filename()))
    {
        throw std::runtime_error("File does not exist");
    }

    m_file.open(
        m_cli.filename(),
        std::ios::binary);

    if (!m_file)
    {
        throw std::runtime_error("Failed to open file");
    }
}

void HexViewer::display()
{
    m_file.seekg(0, std::ios::end);

    const std::size_t fileSize =
        static_cast<std::size_t>(m_file.tellg());

    m_file.seekg(0, std::ios::beg);

    std::cout << "File: "
              << m_cli.filename()
              << '\n';

    std::cout << "Size: "
              << fileSize
              << " bytes\n\n";

    std::vector<unsigned char>
        buffer(m_cli.bytesPerLine());

    std::size_t offset = 0;

    while (
        m_file.read(
            reinterpret_cast<char*>(buffer.data()),
            buffer.size()) ||
        m_file.gcount() > 0)
    {
        const std::size_t count =
            static_cast<std::size_t>(m_file.gcount());

        printOffset(offset);

        printHex(buffer, count);

        printASCII(buffer, count);

        std::cout << '\n';

        offset += count;
    }
}

void HexViewer::printOffset(std::size_t offset) const
{
    if (m_cli.useColor())
    {
        std::cout << CLR_OFFSET;
    }

    std::cout
        << std::setw(8)
        << std::setfill('0')
        << std::hex
        << offset;

    if (m_cli.uppercaseHex())
    {
        std::cout << std::uppercase;
    }

    if (m_cli.useColor())
    {
        std::cout << CLR_RESET;
    }

    std::cout << "  ";
}

void HexViewer::printHex(
    const std::vector<unsigned char>& buffer,
    std::size_t count) const
{
    if (m_cli.useColor())
    {
        std::cout << CLR_HEX;
    }

    for (std::size_t i = 0;
         i < m_cli.bytesPerLine();
         ++i)
    {
        if (i < count)
        {
            std::cout
                << std::setw(2)
                << std::setfill('0')
                << static_cast<int>(buffer[i])
                << ' ';
        }
        else
        {
            std::cout << "   ";
        }

        // Group bytes every 4
        if ((i + 1) % 4 == 0)
        {
            std::cout << ' ';
        }
    }

    if (m_cli.useColor())
    {
        std::cout << CLR_RESET;
    }
}

void HexViewer::printASCII(
    const std::vector<unsigned char>& buffer,
    std::size_t count) const
{
    if (m_cli.useColor())
    {
        std::cout << CLR_ASCII;
    }

    std::cout << "|";

    for (std::size_t i = 0; i < count; ++i)
    {
        const unsigned char c = buffer[i];

        std::cout
            << (std::isprint(c)
                ? static_cast<char>(c)
                : '.');
    }

    std::cout << "|";

    if (m_cli.useColor())
    {
        std::cout << CLR_RESET;
    }
}