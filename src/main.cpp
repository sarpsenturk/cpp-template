#include <iostream>

#include "cpp-template.h"

int main(int argc, const char* const* argv)
{
    (void)argc;
    (void)argv;
    std::cout << cpp_template::hello_world() << '\n';
    return 0;
}