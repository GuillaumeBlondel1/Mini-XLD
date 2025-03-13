#ifndef __ERROR__
    #define __ERROR__

#include <string>
#include <exception>
#include <map>

class Error : public std::exception {
    public:
        Error(const std::string &error) noexcept : _error(error) {}
        const char *what() const noexcept override {return _error.c_str();}
    private:
        std::string _error;
};

namespace WindowManager
{
    class WindowError : public Error {
        public:
            WindowError(const std::string &error) : Error(error) {}
    };

    const std::map<std::size_t, std::string> windowErrorsList = {
        {1, "-E- Open window fail."},
        {2, "-E- Window without size."}
    };
}

#endif
