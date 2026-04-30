#include "SignatureDB.hpp"

namespace
{
    const std::vector<FileSignature> signatures =
    {
        {{0x89, 0x50, 0x4E, 0x47}, "PNG image"},
        {{0xFF, 0xD8, 0xFF},       "JPEG image"},
        {{0x47, 0x49, 0x46},       "GIF image"},
        {{0x25, 0x50, 0x44, 0x46}, "PDF document"},
        {{0x50, 0x4B, 0x03, 0x04}, "ZIP archive"},
        {{0x7F, 0x45, 0x4C, 0x46}, "ELF executable"},
        {{0x4D, 0x5A},             "PE executable"}
    };
}

std::string SignatureDB::detect(
    const std::vector<unsigned char>& buffer)
{
    for (const auto& sig : signatures)
    {
        if (buffer.size() < sig.bytes.size())
        {
            continue;
        }

        bool match = true;

        for (std::size_t i = 0;
             i < sig.bytes.size();
             ++i)
        {
            if (buffer[i] != sig.bytes[i])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            return sig.name;
        }
    }

    return "Unknown";
}