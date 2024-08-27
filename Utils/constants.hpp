#ifndef RAVESLI_CPP_PRACTICE_UTILS_CONSTANTS_HPP
#define RAVESLI_CPP_PRACTICE_UTILS_CONSTANTS_HPP

namespace ravesli_cpp_practice::utils::constants {

template <typename T>
  requires std::integral<T>
constexpr int MAX_DIGITS_COUNT() {
  T max_value = std::numeric_limits<T>::max();
  int digits_count = 0;
  while (max_value > 0) {
    max_value /= 10;
    ++digits_count;
  }
  return digits_count;
}

template <typename T = int>
  requires std::integral<T> || std::floating_point<T>
constexpr T DEC_DIGITS_COUNT = T(10);

template <typename T = int>
  requires std::integral<T> || std::floating_point<T>
constexpr T MIN_MONTH_NUMBER = T(1);

template <typename T = int>
  requires std::integral<T> || std::floating_point<T>
constexpr T MAX_MONTH_NUMBER = T(12);

}  // namespace ravesli_cpp_practice::utils::constants

#endif  // !RAVESLI_CPP_PRACTICE_UTILS_CONSTANTS_HPP