#ifndef __ERROR__
    #define __ERROR__

#include <string>
#include <map>
#include <exception>

class Error : public std::exception {
    public:
        Error(const std::string &error) noexcept : _error(error) {}
        ~Error() = default;
        const char *what() const noexcept {return _error.c_str();}
    private:
        std::string _error;
};

namespace Usage
{
    const std::map<std::size_t, std::string> error = {
        {0, ">> Too many arguments."}
    };
}

namespace File
{
    enum ErrorType {
        EXTENSION = 0,
        OPEN_FILE,
        PARSING,
        DATA_CONFIG,
        INVALID_IP,
        INVALID_PORT,
        INVALID_PATH
    };

    class ConfigFileException : public Error {
        public:
            ConfigFileException(const std::string &error) : Error(error) {}
            ~ConfigFileException() = default;
    };

    const std::map<std::size_t, std::string> error = {
        {EXTENSION, ">> File has not .JSON extension."},
        {OPEN_FILE, ">> Cannot open file."},
        {PARSING, ">> Cannot parse .JSON."},
        {DATA_CONFIG, ">> Data not found in file config."},
        {INVALID_IP, ">> Invalid IP."},
        {INVALID_PORT, ">> Invalid Port."},
        {INVALID_PATH, ">> Invalid Path."}
    };
}

#endif
