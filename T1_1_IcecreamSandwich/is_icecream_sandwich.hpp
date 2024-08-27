#ifndef RAVESLI_CPP_PRACTICE_T1_1_ICECREAM_SANDWICH_IS_ICECREAM_SANDWICH_HPP
#define RAVESLI_CPP_PRACTICE_T1_1_ICECREAM_SANDWICH_IS_ICECREAM_SANDWICH_HPP

#include <string_view>

namespace ravesli_cpp_practice::t1_1_icecream_sandwich {

bool IsIcecreamSandwich(std::string_view str) {
  const auto kLength = str.length();
  if (kLength < 3) {
    return false;
  }

  auto start = 0;
  auto end = kLength - 1;

  const auto kBread = str[start];

  while (start < end && str[start] == str[end] && str[start] == kBread) {
    ++start;
    --end;
  }

  if (start > end) {
    return false;
  }

  const auto kIcecream = str[start];
  if (kIcecream == kBread) {
    return false;
  }

  while (start <= end) {
    if (str[start] != kIcecream) {
      return false;
    }
    ++start;
  }

  return true;
}

}  // namespace ravesli_cpp_practice::t1_1_icecream_sandwich

#endif  // !RAVESLI_CPP_PRACTICE_T1_1_ICECREAM_SANDWICH_IS_ICECREAM_SANDWICH_HPP