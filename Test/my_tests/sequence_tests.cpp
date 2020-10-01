//
// Created by User on 01/10/2020.
//

#include "gtest/gtest.h"

#include "sequence.h"

#include <set>

TEST(BasicSequenceTests, ConstructAndDeref) {
  auto seq{util::sequence(0, 7)};
  EXPECT_EQ(*seq.begin(), 0);
  EXPECT_EQ(*seq.end(), 7);
}

TEST(BasicSequenceTests, BasicUsage) {
  for (const auto v : util::sequence(1, 4)) {
    EXPECT_TRUE(true);
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