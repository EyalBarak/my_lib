//
// Created by User on 01/10/2020.
//

#include "gtest/gtest.h"

#include "sequence.h"

#include <algorithm>
#include <numeric>
#include <set>
#include <string>

TEST(BasicSequenceTests, ConstructAndDeref) {
  auto seq {util::sequence(0, 7)};
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
  auto          seq {util::sequence(0, 12)};
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

TEST(BasicSequenceTests, CharTest) {
  auto result {std::string(5, 'a')};
  EXPECT_EQ(result, "aaaaa");
  auto seq {util::sequence('a', 'f')};
  std::copy(seq.cbegin(), seq.cend(), result.begin());
  EXPECT_EQ(result, "abcde");
}

TEST(BasicSequenceTests, DefaultTest) {
  auto vec1 = []() {
    std::vector<int> result;
    for (const auto i : util::sequence(10)) {
      result.push_back(i);
    }
    return result;
  }();
  auto vec2 = []() {
    std::vector<int> result;
    for (auto i {0}; i < 10; i++) {
      result.push_back(i);
    }
    return result;
  }();
  EXPECT_EQ(vec1, vec2);
}

class UnsignedIntPTests : public testing::TestWithParam<int> {};

TEST_P(UnsignedIntPTests, ArithmeticSumFromZero) {
  auto sum {0};
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
    auto             seq {util::sequence(0, GetParam())};
    std::copy(seq.begin(), seq.end(), result.begin());
    return result;
  }();
  EXPECT_EQ(vec1, vec2);
}

INSTANTIATE_TEST_SUITE_P(UnsignedPs, UnsignedIntPTests, testing::Range(0, 20));

TEST(IndicesTest, WithIota) {
  auto             len {12};
  std::vector<int> vec(len);
  std::iota(vec.begin(), vec.end(), 0);

  auto count {0};
  for (const auto i : util::indices(vec)) {
    EXPECT_EQ(i, vec[i]);
    count++;
  }
  EXPECT_EQ(count, len);
}