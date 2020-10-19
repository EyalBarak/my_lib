//
// Created by User on 19/10/2020.
//

#include "gtest/gtest.h"

#include "meta.h"

TEST(CountArguments, Basic) {
  constexpr auto f = [](int, int, int) {};
  static_assert(util::count_arguments(f) == 3);

  static_assert(util::count_arguments([](int) mutable {}) == 1);
  static_assert(util::count_arguments([](int) {}) == 1);
  static_assert(util::count_arguments([] {}) == 0);
  static_assert(util::count_arguments([]() mutable {}) == 0);
}