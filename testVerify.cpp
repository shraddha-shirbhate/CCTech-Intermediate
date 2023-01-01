#include <iostream>
#include "verify.h"

int main(int argc, char* argv[])
{
    std::cout << "Main starts :\n";
    verify(2 == 2);
    //verify(1 == 2);
    std::cout << "Main ends :\n";
    return EXIT_SUCCESS;
}