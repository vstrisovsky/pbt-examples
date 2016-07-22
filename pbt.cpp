#include "catch.hpp"
#include "quicksort.h"
#include "cppqc.h"
#include "cppqc/CompactCheck.h"

TEST_CASE( "property based testing: quick sort", "[pbt]" )
{
  SECTION("the output shoud be ordered")
  {
      auto test = cppqc::gen<std::vector<int>>()
          .property("sorting should be sorted",
            [](const std::vector<int>& v)
            {
                std::vector<int> sortedCollection(v);
                quicksort(sortedCollection.begin(), sortedCollection.end());
                return std::is_sorted(sortedCollection.begin(), sortedCollection.end());
            });

      REQUIRE(test.testWithOutput().result == cppqc::QC_SUCCESS);
  }

  SECTION("the output should be permutation of the input")
  {
      auto test = cppqc::gen<std::vector<int>>()
          .property("input - output permutation",
            [](const std::vector<int>& v)
            {
                std::vector<int> sortedCollection(v);
                quicksort(sortedCollection.begin(), sortedCollection.end());
                return std::is_permutation(sortedCollection.begin(), sortedCollection.end(), v.begin());
            })
        .trivial
          ([](const std::vector<int>& v)
          {
            return v.size() == 0;
          })
        .classify
          ([](const std::vector<int>& v)
          {
              return std::to_string(v.size());
          });

      REQUIRE(test.testWithOutput().result == cppqc::QC_SUCCESS);
  }
}
