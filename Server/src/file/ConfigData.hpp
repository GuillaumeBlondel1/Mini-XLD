#ifndef __CONFIGDATA__
    #define __CONFIGDATA__

#include <string>

#define IP_DATA "serverIp"
#define PORT_DATA "serverPort"
#define PATH_DATA "serverPath"

namespace File
{
    class Ip {
        public:
            Ip() = default;
            Ip(const std::string &ip);
            ~Ip() = default;
            void setIp(const std::string &ip);
            const std::string getIp() const;
            bool invalidIp() const;
        private:
            std::string _ip;
    };

    class Port {
        public:
            Port();
            Port(unsigned int port);
            ~Port() = default;
            void setPort(unsigned int port);
            unsigned int getPort() const;
            bool invalidPort() const;
        private:
            unsigned int _port;
    };

    class Path {
        public:
            Path() = default;
            Path(const std::string &path);
            ~Path() = default;
            void setPath(const std::string &path);
            const std::string getPath() const;
            bool invalidPath() const;
        private:
            std::string _path;
    };

    class ConfigData : public Ip, public Port, public Path {};
}

#endif
