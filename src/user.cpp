#include "user.h"


std::uint64_t User::_ID = 0;


User::User(const std::string &_u, const std::string &_p)
: _username(_u), _pwd(_p)
{
    this->_id = _ID++;
}


User::User() : User("", "")
{    }


const std::string &
User::username() const noexcept
{ return this->_username; }

const std::string &
User::pwd() const noexcept
{ return this->_pwd; }

std::uint64_t
User::id() const noexcept
{ return this->_id; }

