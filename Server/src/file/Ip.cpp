#include "ConfigData.hpp"

#include "../extra/ExStrings.hpp"

File::Ip::Ip(const std::string &ip) : _ip(ip) {}

void File::Ip::setIp(const std::string &ip)
{
    _ip = ip;
}

const std::string File::Ip::getIp() const
{
    return _ip;
}

bool File::Ip::invalidIp() const
{
    std::vector<std::string> splitIp = ExString::splitStr(_ip, ".");
    if (splitIp.size() != 4) {
        return true;
    }
    return false;
}
