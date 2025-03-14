#include "Account.hpp"

Account::Account(const std::string &username, const std::string password) : _username(username), _password(password) {}

Account::Account(const Account &other)
{
    _username = other._username;
    _password = other._password;
}

void Account::setUsername(const std::string &username)
{
    _username = username;
}

void Account::setPassword(const std::string &password)
{
    _password = password;
}

const std::string &Account::getUsername() const
{
    return _username;
}

const std::string &Account::getPassword() const
{
    return _password;
}

void Account::operator=(const Account &other)
{
    _username = other._username;
    _password = other._password;
}

bool Account::operator==(const Account &other) const
{
    if (_username == other._username && _password == other._password) {
        return true;
    }
    return false;
}

bool Account::operator!=(const Account &other) const
{
    if (_username != other._username || _password != other._password) {
        return true;
    }
    return false;
}
