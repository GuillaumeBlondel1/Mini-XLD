#include "usage/Usage.hpp"
#include "file/ConfigFile.hpp"
#include "Error.hpp"

#include <iostream>

int main(int argc, const char **argv)
{
    Usage::usage(argc, argv);
    File::ConfigFile configFile(argv[1]);

    try {
        configFile.read();
        configFile.getConfig();
    } catch (File::ConfigFileException &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}