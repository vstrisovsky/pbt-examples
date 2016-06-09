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
      bool trivial(const std::vector<int> &v) const override
      {
          return v.size() == 0 || v.size() == 1;
      }
      std::string classify(const std::vector<int> &v) const override
      {
          return std::to_string(v.size());
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
      bool trivial(const std::vector<int> &v) const override
      {
          return v.size() == 0 || v.size() == 1;
      }
      std::string classify(const std::vector<int> &v) const override
      {
          return std::to_string(v.size());
      }
  };

  SECTION("the output shoud be permutation of the input")
  {
      REQUIRE(cppqc::quickCheckOutput(QuickSortPermutation()).result == cppqc::QC_SUCCESS);
  }

}
