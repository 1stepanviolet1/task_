#pragma once

#include <string>
#include <cstdint>


class User
{
public:
    User(const std::string &_u, const std::string &_p);
    User();

    const std::string & username() noexcept;
    const std::string & pwd() noexcept;


private:
    std::string _username;
    std::string _pwd;

};

