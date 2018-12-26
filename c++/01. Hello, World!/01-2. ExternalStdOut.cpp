#include <iostream>
#include <unistd.h>

int main() {
    std::cout << "My Process ID is " << getpid() << "!" << std::endl;
    while(1)
    {
        sleep(1);
    }
    return 1;
}