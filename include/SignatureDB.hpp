#pragma once

#include <string>
#include <vector>

struct FileSignature
{
    std::vector<unsigned char> bytes;

    std::string name;
};

class SignatureDB
{
public:
    static std::string detect(
        const std::vector<unsigned char>& buffer);
};