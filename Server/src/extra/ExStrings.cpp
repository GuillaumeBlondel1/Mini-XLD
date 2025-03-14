#include "ExStrings.hpp"

#include <sstream>

std::vector<std::string> ExString::splitStr(const std::string &str, const std::string &delimiters)
{
    std::string cpyStr = str;
    std::vector<std::string> split;
    std::size_t i = 0;

    while (i < cpyStr.length()) {
        if (delimiters.find(cpyStr.at(i)) != std::string::npos) {
            std::string tmpStr = cpyStr.substr(0, i);
            cpyStr.erase(0, (i + 1));
            i = 0;
            if (tmpStr.empty()) {
                continue;
            }
            split.push_back(tmpStr);
            continue;
        }
        i++;
    }
    if (!cpyStr.empty()) {
        split.push_back(cpyStr);
    }
    return split;
}

std::string ExString::convertFileToStr(const std::ifstream &file)
{
    std::string fileStr;

    if (!file.is_open()) {
        return fileStr;
    }
    std::ostringstream fileConvert;
    fileConvert << file.rdbuf();
    fileStr = fileConvert.str();
    return fileStr;
}

std::string ExString::convertFileToStr(const std::ofstream &file)
{
    std::string fileStr;

    if (!file.is_open()) {
        return fileStr;
    }
    std::ostringstream fileConvert;
    fileConvert << file.rdbuf();
    fileStr = fileConvert.str();
    return fileStr;
}
