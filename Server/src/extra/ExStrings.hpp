#ifndef __EXSTRINGS__
    #define __EXSTRINGS__

#include <string>
#include <fstream>
#include <vector>

namespace ExString
{
    std::vector<std::string> splitStr(const std::string &str, const std::string &delimiters);
    std::string convertFileToStr(const std::ifstream &file);
    std::string convertFileToStr(const std::ofstream &file);
}

#endif
