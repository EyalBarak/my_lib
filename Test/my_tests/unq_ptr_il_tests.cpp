//
// Created by User on 15/10/2020.
//

#include "gtest/gtest.h"

#include "unique_ptr_init_list.h"

#include <memory>
#include <set>
#include <sstream>
#include <vector>

class C {
public:
  explicit C(std::initializer_list<util::unique_ptr_in_il<int>> list) :
      vec_(list.begin(), list.end()) {}

  const std::vector<std::unique_ptr<int>>& data() const noexcept {
    return vec_;
  }

  std::vector<std::unique_ptr<int>>& data() noexcept { return vec_; }

private:
  std::vector<std::unique_ptr<int>> vec_;
};

class D {
public:
  D(std::initializer_list<util::unique_ptr_in_il<char>> list) :
      set_(list.begin(), list.end()) {}

  const std::set<std::unique_ptr<char>>& data() const noexcept { return set_; }

  std::set<std::unique_ptr<char>>& data() noexcept { return set_; }

private:
  std::set<std::unique_ptr<char>> set_;
};

TEST(BasicTests, TrivialUsage) {
  const C           c {std::make_unique<int>(5), std::make_unique<int>(6)};
  std::stringstream stream {};
  for (const auto& p : c.data())
    stream << *p;
  EXPECT_EQ(stream.str(), "56");

  const D d {std::make_unique<char>(' '), std::make_unique<char>(' '),
             std::make_unique<char>('a'), std::make_unique<char>('b')};
  for (const auto& p : d.data())
    std::cout << *p << ' ';
  std::cout << std::endl;
}
