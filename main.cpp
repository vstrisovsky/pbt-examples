#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include <iostream>

namespace Catch

{
std::ostream& cout()
{
    return std::cout;
};

std::ostream& cerr()
{
    return std::cerr;
};

}
