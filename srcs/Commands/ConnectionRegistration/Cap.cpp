#include <IRC.hpp>

void Commands::cap_cmd(User *user, IRC *server)
{
    (void)user;
    (void)server;
    #if DEBUG == 1
        std::cout << RED << "ENTER CAP CMD" << NC << std::endl;
        std::cout << RED << "EXIT CAP CMD" << NC << std::endl;
    #endif
    //à ignorer
}
