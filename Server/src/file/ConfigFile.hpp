#ifndef __FILECONFIG__
    #define __FILECONFIG__

#include "ConfigData.hpp"

#include <fstream>
#include <string>

#include <nlohmann/json.hpp>

namespace File
{
    class ConfigFile : public ConfigData {
        public:
            ConfigFile() = default;
            ConfigFile(const std::string &filename);
            ~ConfigFile();
            void read();
            void clear();
            bool isEmptyConfigFile() const;
            void getConfig();
        private:
            std::string _filename;
            nlohmann::json _jsonConfig;
    };
}

#endif
