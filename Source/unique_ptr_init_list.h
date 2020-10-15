//
// Created by User on 15/10/2020.
//

#ifndef MY_LIB_UNIQUE_PTR_INIT_LIST_H
#define MY_LIB_UNIQUE_PTR_INIT_LIST_H

#include <memory>

namespace util {

  template<typename Type> class unique_ptr_in_il final {
  public:
    unique_ptr_in_il()                        = delete;
    unique_ptr_in_il(const unique_ptr_in_il&) = delete;
    unique_ptr_in_il(unique_ptr_in_il&&)      = delete;
    unique_ptr_in_il& operator=(const unique_ptr_in_il&) = delete;
    unique_ptr_in_il& operator=(unique_ptr_in_il&&) = delete;

    ~unique_ptr_in_il() noexcept = default;

    unique_ptr_in_il(std::unique_ptr<Type>&& ptr) noexcept :
        ptr_(std::move(ptr)) {}

    operator std::unique_ptr<Type>() const noexcept { return std::move(ptr_); }

  private:
    mutable std::unique_ptr<Type> ptr_;
  };
} // namespace util

#endif // MY_LIB_UNIQUE_PTR_INIT_LIST_H
