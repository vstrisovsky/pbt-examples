#include "catch.hpp"
#include "quicksort.h"
#include "cppqc.h"


TEST_CASE( "property based testing: quick sort", "[pbt]" )
{
  struct QuickSortOrdered : cppqc::Property<std::vector<int>>
  {
      bool check(const std::vector<int> &v) const override
      {
          std::vector<int> sortedCollection(v);
          quicksort(sortedCollection.begin(), sortedCollection.end());
          return std::is_sorted(sortedCollection.begin(), sortedCollection.end());
      }
      std::string name() const override
    {
        return "sorting should be sorted";
    }
  };

  SECTION("the output shoud be ordered")
  {
      REQUIRE(cppqc::quickCheckOutput(QuickSortOrdered()).result == cppqc::QC_SUCCESS);
  }

  struct QuickSortPermutation : cppqc::Property<std::vector<int>>
  {
      bool check(const std::vector<int> &v) const override
      {
          std::vector<int> sortedCollection(v);
          quicksort(sortedCollection.begin(), sortedCollection.end());
          return std::is_permutation(sortedCollection.begin(), sortedCollection.end(), v.begin());
      }
      std::string name() const override
      {
          return "input - output permutation";
      }
  };

  SECTION("the output shoud be permutation of the input")
  {
      REQUIRE(cppqc::quickCheckOutput(QuickSortPermutation()).result == cppqc::QC_SUCCESS);
  }

}
