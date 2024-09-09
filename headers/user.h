#pragma once

#include <string>
#include <cstdint>


class User
{
public:
    User(const std::string &_u, const std::string &_p);
    User();

    const std::string & username() const noexcept;
    const std::string & pwd() const noexcept;
    std::uint64_t id() const noexcept;

private:
    std::string _username;
    std::string _pwd;
    std::uint64_t _id;
    
    static std::uint64_t _ID;
};

