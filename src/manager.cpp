#include "manager.h"


Manager_of_users::Manager_of_users()
{    }


std::uint64_t
Manager_of_users::new_user(const std::string &_u, const std::string &_p)
{
    this->_pool.emplace_back(_u, _p);
    return (--(this->_pool.end()))->id();
}


const User &
Manager_of_users::get(std::uint64_t _id) const
{ return this->_pool.at(_id); }


std::size_t
Manager_of_users::size() const noexcept
{ return this->_pool.size(); }

