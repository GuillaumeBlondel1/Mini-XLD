#ifndef __ACCOUNT__
    #define __ACCOUNT__

#include <string>

class Account {
    public:
        Account() = default;
        Account(const std::string &username, const std::string password);
        Account(const Account &other);
        void setUsername(const std::string &username);
        void setPassword(const std::string &password);
        const std::string &getUsername() const;
        const std::string &getPassword() const;
        ~Account() = default;
        void operator=(const Account &other);
        bool operator==(const Account &other) const;
        bool operator!=(const Account &other) const;
    private:
        std::string _username;
        std::string _password;
};

#endif
