#include "CLI.hpp"
#include "HexViewer.hpp"
#include "Terminal.hpp"
#include <iostream>

int main(int argc, char* argv[])
{
    try
    {

        enableVirtualTerminal();
        CLI cli(argc, argv);

        if (cli.showHelp())
        {
            cli.printHelp();
            return 0;
        }

        HexViewer viewer(cli);

        viewer.display();
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