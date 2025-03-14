#include "ConfigData.hpp"

#include "../Error.hpp"

#include <iostream>

File::Users::Users(const nlohmann::json &usersList)
{
    for (auto it = usersList.begin(); it != usersList.end(); ++it) {
        Account newAccount;
        try {
            newAccount.setUsername((*it)["username"]);
            newAccount.setPassword((*it)["password"]);
        } catch (nlohmann::detail::type_error &e) {
            std::cerr << e.what() << std::endl;
            throw File::ConfigFileException(File::error.find(DATA_CONFIG)->second);
        }
        _registerAccounts.push_back(newAccount);
    }
}

void File::Users::setUsers(const nlohmann::json &usersList)
{
    for (auto it = usersList.begin(); it != usersList.end(); ++it) {
        Account newAccount;
        try {
            newAccount.setUsername((*it)["username"]);
            newAccount.setPassword((*it)["password"]);
        } catch (nlohmann::detail::type_error &e) {
            throw nlohmann::detail::type_error(e);
        }
        _registerAccounts.push_back(newAccount);
    }
}

const std::vector<Account> &File::Users::getUsers() const
{
    return _registerAccounts;
}

void File::Users::addUser(const Account &account)
{
    _registerAccounts.push_back(Account(account));
}

bool File::Users::userExisting(const Account &account) const
{
    for (auto it = _registerAccounts.begin(); it != _registerAccounts.end(); ++it) {
        if ((*it) == account) {
            return true;
        }
    }
    return false;
}
