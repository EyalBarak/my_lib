//
// Created by User on 01/10/2020.
//

#ifndef MY_LIB_SEQUENCE_H
#define MY_LIB_SEQUENCE_H

#include <type_traits>

namespace util {

template <typename T> class Sequence final {
  static_assert(std::is_integral<T>::value);

public:
  Sequence() = delete;
  constexpr Sequence(const Sequence &other) noexcept = default;
  constexpr Sequence(Sequence &&other) noexcept = default;
  constexpr Sequence &operator=(const Sequence &rhs) noexcept = default;
  constexpr Sequence &operator=(Sequence &&rhs) noexcept = default;
  ~Sequence() noexcept = default;

  constexpr Sequence(T beg, T end) noexcept : beg_{beg}, end_{end} {}

  class iterator {
  public:
    iterator() = delete;
    constexpr iterator(const iterator &other) noexcept = default;
    constexpr iterator(iterator &&other) noexcept = default;
    constexpr iterator &operator=(const iterator &rhs) noexcept = default;
    constexpr iterator &operator=(iterator &&rhs) noexcept = default;
    ~iterator() noexcept = default;

    constexpr explicit iterator(T val) noexcept : val_(val) {}

    constexpr T operator*() const noexcept { return val_; }

    constexpr iterator &operator++() noexcept {
      val_++;
      return *this;
    }

    constexpr iterator operator++(int) noexcept { return iterator{val_++}; }

    constexpr bool operator==(const iterator &rhs) noexcept {
      return val_ == rhs.val_;
    }

    constexpr bool operator!=(const iterator &rhs) noexcept {
      return !(*this == rhs);
    }

  private:
    T val_;
  };
  constexpr iterator begin() noexcept { return cbegin(); }
  constexpr iterator end() noexcept { return cend(); }

  using const_iterator = iterator;
  constexpr const_iterator cbegin() const noexcept {
    return const_iterator{beg_};
  }
  constexpr const_iterator cend() const noexcept {
    return const_iterator{end_};
  }
  constexpr const_iterator begin() const noexcept { return cbegin(); }
  constexpr const_iterator end() const noexcept { return cend(); }

private:
  const T beg_, end_;
};

template <typename T> constexpr Sequence<T> sequence(T beg, T end) noexcept {
  return {beg, end};
}

} // namespace util

#endif // MY_LIB_SEQUENCE_H
