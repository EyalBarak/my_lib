//
// Created by User on 01/10/2020.
//

#include "gtest/gtest.h"

#include "sequence.h"

TEST(BasicSequenceTests, ConstructAndDeref) {
  auto seq{util::sequence(0, 7)};
  EXPECT_EQ(*seq.begin(), 0);
}