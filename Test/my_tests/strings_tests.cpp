//
// Created by User on 16/10/2020.
//

#include "gtest/gtest.h"

#include "string_algs.h"

#include <string>

TEST(SplitTests, Basic) {
  std::string              str {" try to split "};
  auto                     result {util::string_split(str)};
  std::vector<std::string> expected {"try", "to", "split"};
  EXPECT_EQ(result, expected);
}

TEST(SplitTests, IntString) {
  std::basic_string<int>              str {1, 1, 2, 1, 1, 2, 1, 0, 1};
  auto                                result {util::string_split(str, 1)};
  std::vector<std::basic_string<int>> expected {{2}, {2}, {0}};
  EXPECT_EQ(result, expected);
}