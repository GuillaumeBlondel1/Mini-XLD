#include "ConfigData.hpp"

#include <filesystem>

File::Path::Path(const std::string &path) : _path(path) {}

void File::Path::setPath(const std::string &path)
{
    _path = path;
}

const std::string File::Path::getPath() const
{
    return _path;
}

bool File::Path::invalidPath() const
{
    if (_path.empty()) {
        return true;
    }
    if (!std::filesystem::exists(std::filesystem::path(_path))) {
        return true;
    }
    return false;
}