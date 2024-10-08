﻿#ifndef RAVESLI_CPP_PRACTICE_UTILS_PARSE_HPP
#define RAVESLI_CPP_PRACTICE_UTILS_PARSE_HPP

#include <cmath>
#include <concepts>
#include <sstream>
#include <stdexcept>
#include <string>

namespace ravesli_cpp_practice::utils::parse {

template <typename T>
  requires std::integral<T> || std::floating_point<T>
T Parse(const std::string& str) {
  T value{};
  std::istringstream iss(str);
  iss >> value;

  if (iss.fail() || !iss.eof()) {
    throw std::invalid_argument("invalid parse argument");
  }

  if constexpr (std::integral<T>) {
    if (value < std::numeric_limits<T>::lowest() ||
        value > std::numeric_limits<T>::max()) {
      throw std::out_of_range("parse argument out of range");
    }
  }

  return value;
}

}  // namespace ravesli_cpp_practice::utils::parse

#endif  // !RAVESLI_CPP_PRACTICE_UTILS_PARSE_HPP