//
// Created by User on 01/10/2020.
//

#include "gtest/gtest.h"

#include "sequence.h"

#include <algorithm>
#include <numeric>
#include <set>

TEST(BasicSequenceTests, ConstructAndDeref) {
  auto seq{util::sequence(0, 7)};
  EXPECT_EQ(*seq.begin(), 0);
  EXPECT_EQ(*seq.end(), 7);
}

TEST(BasicSequenceTests, BasicUsage) {
  for (const auto v : util::sequence(1, 4)) {
    EXPECT_TRUE(true);
    EXPECT_GT(v, 0);
  }
}

TEST(BasicSequenceTests, BasicUsageCorrectness) {
  auto seq{util::sequence(0, 12)};
  std::set<int> flags;
  EXPECT_TRUE(flags.empty());
  for (const auto i : seq) {
    flags.insert(i);
  }
  EXPECT_EQ(flags.size(), 12);
  for (auto i = 0; i < 12; i++) {
    EXPECT_NE(flags.find(i), flags.end());
  }
}

class UnsignedIntPTests : public testing::TestWithParam<int> {};

TEST_P(UnsignedIntPTests, ArithmeticSumFromZero) {
  auto sum{0};
  for (const auto i : util::sequence(0, GetParam())) {
    sum += i;
  }
  EXPECT_EQ(sum, ((GetParam() - 1) * GetParam()) / 2);
}

TEST_P(UnsignedIntPTests, SameAsIota) {
  const auto vec1 = []() {
    std::vector<int> result(GetParam(), 0);
    std::iota(result.begin(), result.end(), 0);
    return result;
  }();
  const auto vec2 = []() {
    std::vector<int> result(GetParam(), 0);
    auto seq{util::sequence(0, GetParam())};
    std::copy(seq.begin(), seq.end(), result.begin());
    return result;
  }();
  EXPECT_EQ(vec1, vec2);
}

INSTANTIATE_TEST_SUITE_P(UnsignedPs, UnsignedIntPTests, testing::Range(0, 20));