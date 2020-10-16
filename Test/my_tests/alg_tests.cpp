//
// Created by User on 16/10/2020.
//

#include "gtest/gtest.h"

#include "algorithms.h"

#include <iterator>
#include <string>
#include <vector>

TEST(SplitTransfom, SplitStringToVector) {
  std::string              hello {"  try to  split me   "};
  std::vector<std::string> vec {};
  util::split_transform(
      hello.cbegin(), hello.cend(), ' ', std::inserter(vec, vec.begin()),
      [](auto start, auto end) { return std::string(start, end); });
  std::vector<std::string> expected {"try", "to", "split", "me"};
  EXPECT_EQ(vec, expected);
}

TEST(SplitTransform, EmptyStrings) {
  std::string              str1 {""};
  std::vector<std::string> vec1 {};
  util::split_transform(
      str1.cbegin(), str1.cend(), ' ', std::inserter(vec1, vec1.begin()),
      [](auto start, auto end) { return std::string(start, end); });
  std::vector<std::string> expected {};
  EXPECT_EQ(vec1, expected);

  str1 = "       ";
  util::split_transform(
      str1.cbegin(), str1.cend(), ' ', std::inserter(vec1, vec1.begin()),
      [](auto start, auto end) { return std::string(start, end); });
  EXPECT_EQ(vec1, expected);
}

TEST(SplitTransform, Trivial) {
  std::string              str1 {"one_word"};
  std::vector<std::string> vec1 {};
  util::split_transform(
      str1.cbegin(), str1.cend(), ' ', std::inserter(vec1, vec1.begin()),
      [](auto start, auto end) { return std::string(start, end); });
  std::vector<std::string> expected {"one_word"};
  EXPECT_EQ(vec1, expected);
}