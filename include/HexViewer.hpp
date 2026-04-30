#pragma once

#include "CLI.hpp"

#include <fstream>
#include <string>
#include <vector>

class HexViewer
{
public:
    explicit HexViewer(const CLI& cli);

    void display();

private:
    void printOffset(std::size_t offset) const;

    void printHex(
        const std::vector<unsigned char>& buffer,
        std::size_t count) const;

    void printASCII(
        const std::vector<unsigned char>& buffer,
        std::size_t count) const;

private:
    const CLI& m_cli;

    std::ifstream m_file;
};