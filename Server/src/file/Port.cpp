#include "ConfigData.hpp"

File::Port::Port() : _port(0) {}

File::Port::Port(unsigned int port) : _port(port) {}

void File::Port::setPort(unsigned int port)
{
    _port = port;
}

unsigned int File::Port::getPort() const
{
    return _port;
}

bool File::Port::invalidPort() const
{
    if (_port == 0) {
        return true;
    }
    return false;
}
