#ifndef RAVESLI_CPP_PRACTICE_UTILS_MATH_HPP
#define RAVESLI_CPP_PRACTICE_UTILS_MATH_HPP

#include <concepts>

namespace ravesli_cpp_practice::utils::math {

template <typename T>
concept number = std::integral<T> || std::floating_point<T>;

template <typename T>
  requires number<T>
constexpr auto Pow(T number, int exponent) {
  T result = 1;
  while (exponent-- > 0) {
    result *= number;
  }
  return result;
};

}  // namespace ravesli_cpp_practice::utils::math

#endif  // !RAVESLI_CPP_PRACTICE_UTILS_MATH_HPP