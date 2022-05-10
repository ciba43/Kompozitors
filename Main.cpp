#include <iostream>

#include "Server.h"

int main(int argc, char** argv)
{
    std::cout << "Hello World" << std::endl;
    Server server;

    if (server.init())
        server.run();
    else
        return 1;

    return 0;
}
