#include "CLI.hpp"

#include <iostream>

int main(int argc, char* argv[])
{
    try
    {
        CLI cli(argc, argv);

        if (cli.showHelp())
        {
            cli.printHelp();
            return 0;
        }

        std::cout << "File: "
                  << cli.filename()
                  << '\n';

        std::cout << "Bytes per line: "
                  << cli.bytesPerLine()
                  << '\n';

        std::cout << "Color: "
                  << (cli.useColor() ? "enabled" : "disabled")
                  << '\n';

        std::cout << "Uppercase: "
                  << (cli.uppercaseHex() ? "yes" : "no")
                  << '\n';
    }
    catch (const std::exception& ex)
    {
        std::cerr << "Error: "
                  << ex.what()
                  << '\n';

        return 1;
    }

    return 0;
}