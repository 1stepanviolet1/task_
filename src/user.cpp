#include "user.h"


User::User(const std::string &_u, const std::string &_p)
: _username(_u), _pwd(_p)
{    }


User::User() : User("", "")
{    }


const std::string &
User::username() noexcept
{ return this->_username; }

const std::string &
User::pwd() noexcept
{ return this->_pwd; }

