#include "catch.hpp"

#include "quicksort.h"

TEST_CASE( "quick sort", "[ebt]" )
{
    SECTION("sort empty vector")
    {
        std::vector<int> coll{};
        quicksort(coll.begin(), coll.end());
        REQUIRE( coll == std::vector<int>({}));
    }
    SECTION("sort vector with one item")
    {
        std::vector<int> coll{1};
        quicksort(coll.begin(), coll.end());
        REQUIRE( coll == std::vector<int>({1}));
    }
    SECTION("sort vector")
    {
        std::vector<int> coll{6,4,3,7,8,1,29,0};
        quicksort(coll.begin(), coll.end());
        REQUIRE( coll == std::vector<int>({0,1,3,4,6,7,8,29}));
    }
    SECTION("sort vector with duplicates")
    {
        std::vector<int> coll{6,4,3,6,6,3,3};
        quicksort(coll.begin(), coll.end());
        REQUIRE( coll == std::vector<int>({3,3,3,4,6,6,6}));
    }
}
