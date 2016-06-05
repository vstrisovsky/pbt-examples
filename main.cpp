#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "quicksort.h"

TEST_CASE( "quick sort", "..." )
{
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
