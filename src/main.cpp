#include <iostream>

#include "manager.h"


int main()
{
    Manager_of_users manager;
    
    manager.new_user("user1", "pwd1");
    manager.new_user("user2", "pwd2");

    std::cout << manager.get(1).username() << std::endl;
    std::cout << manager.size() << std::endl;

    return 0;

}

