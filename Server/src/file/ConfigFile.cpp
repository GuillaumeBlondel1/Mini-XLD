#include "ConfigFile.hpp"

#include "../Error.hpp"
#include "../extra/ExStrings.hpp"

#include <filesystem>
#include <iostream>

File::ConfigFile::ConfigFile(const std::string &filename) : _filename(filename) {}

File::ConfigFile::~ConfigFile()
{
    _jsonConfig.clear();
}

void File::ConfigFile::read()
{
    std::filesystem::path filePath(_filename);

    if (filePath.extension() != ".json" && filePath.extension() != ".JSON") {
        throw File::ConfigFileException(File::error.find(EXTENSION)->second);
    }
    std::ifstream file;
    file.open(_filename);
    if (!file.is_open()) {
        throw File::ConfigFileException(File::error.find(OPEN_FILE)->second);
    }
    try {
        _jsonConfig = nlohmann::json::parse(ExString::convertFileToStr(file));
    } catch (nlohmann::detail::parse_error &e) {
        file.close();
        std::cerr << e.what() << std::endl;
        throw File::ConfigFileException(File::error.find(PARSING)->second);
    }
    file.close();
}

void File::ConfigFile::clear()
{
    _jsonConfig.clear();
}

bool File::ConfigFile::isEmptyConfigFile() const
{
    return _jsonConfig.empty();
}

void File::ConfigFile::getConfig()
{
    try {
        this->setIp(_jsonConfig[IP_DATA]);
        this->setPort(_jsonConfig[PORT_DATA]);
        this->setPath(_jsonConfig[PATH_DATA]);
        this->setUsers(_jsonConfig[USERS_DATA]);
    } catch (nlohmann::detail::type_error &e) {
        std::cerr << e.what() << std::endl;
        throw File::ConfigFileException(File::error.find(DATA_CONFIG)->second);
    }
    if (this->invalidIp()) {
        throw File::ConfigFileException(File::error.find(INVALID_IP)->second);
    }
    if (this->invalidPort()) {
        throw File::ConfigFileException(File::error.find(INVALID_PORT)->second);
    }
    if (this->invalidPath()) {
        throw File::ConfigFileException(File::error.find(INVALID_PATH)->second);
    }
}
