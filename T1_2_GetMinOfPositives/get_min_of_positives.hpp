#ifndef RAVESLI_CPP_PRACTICE_T1_2_GET_MIN_OF_POSITIVES_GET_MIN_OF_POSITIVES_HPP
#define RAVESLI_CPP_PRACTICE_T1_2_GET_MIN_OF_POSITIVES_GET_MIN_OF_POSITIVES_HPP

#include <algorithm>
#include <concepts>
#include <functional>
#include <ranges>
#include <vector>

namespace ravesli_cpp_practice::t1_2_get_min_of_positives {

template <typename T>
  requires std::integral<T> || std::floating_point<T>
T GetMinOfPositives(const std::vector<T>& positive_numbers) {
  std::function<bool(T)> invalid_value_predicate;
  if constexpr (std::floating_point<T>) {
    invalid_value_predicate = [](T number) {
      return std::isnan(number) || std::isinf(number) || number <= 0;
    };
  } else {
    invalid_value_predicate = [](T number) { return number <= 0; };
  }

  if (std::ranges::any_of(positive_numbers, invalid_value_predicate)) {
    throw std::invalid_argument(
        "the provided sequence contains invalid values");
  }
  return std::ranges::min(positive_numbers);
}

}  // namespace ravesli_cpp_practice::t1_2_get_min_of_positives

#endif  // !RAVESLI_CPP_PRACTICE_T1_2_GET_MIN_OF_POSITIVES_GET_MIN_OF_POSITIVES_HPP