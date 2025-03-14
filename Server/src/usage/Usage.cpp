#include "Usage.hpp"

#include "../Error.hpp"

#include <cstring>
#include <iostream>

void Usage::usage(int argc, const char **argv)
{
    if (argc == 1) {
        std::cout << help;
        std::exit(1);
    }
    if (argc == 2) {
        if (!std::strcmp(argv[1], "-h")) {
            std::cout << help;
            std::exit(0);
        }
        return;
    }
    std::cerr << Usage::error.find(0)->second << std::endl;
    std::exit(1);
}
