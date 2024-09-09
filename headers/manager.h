#pragma once

#include <vector>
#include <cstdint>
#include <string>

#include "user.h"


class Manager_of_users
{
public:
    Manager_of_users();

    std::uint64_t new_user(const std::string &_u, const std::string &_p);

    const User & get(std::uint64_t _id) const;

    std::size_t size() const noexcept;

private:
    std::vector<User> _pool;

};

