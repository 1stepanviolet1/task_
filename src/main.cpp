#include <iostream>

#include "user.h"

int main()
{
    User u1("user1", "pwd1");
    User u2("user2", "pwd2");

    std::cout << u1.username() << " " << u2.pwd() << std::endl;

    return 0;

}

