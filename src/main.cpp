#include "ConfigParser.hpp"
#include "utils.hpp"

#include <cassert>
#include <iostream>


int main()
{
    ConfigParser parser("../configs/test.config");
    std::cout << parser["message"].getValue() << std::endl;
    std::cout << parser["message_2"].getValue() << std::endl;
}