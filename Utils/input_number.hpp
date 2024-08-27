#ifndef RAVESLI_CPP_PRACTICE_UTILS_INPUT_NUMBER_HPP
#define RAVESLI_CPP_PRACTICE_UTILS_INPUT_NUMBER_HPP

#include <concepts>
#include <functional>
#include <optional>
#include <stdexcept>
#include <string>

#include "exceptions.hpp"
#include "parse.hpp"

namespace ravesli_cpp_practice::utils::input_number {

template <typename T>
  requires std::integral<T> || std::floating_point<T>
std::optional<T> InputNumber(
    const std::optional<std::function<bool(T)>>& validator = {},
    const std::optional<std::function<void(const std::exception&)>> on_error =
        {},
    const std::optional<std::function<bool(const std::string&)>>&
        return_condition = {}) {
  T number;
  std::string input;
  while (true) {
    try {
      getline(std::cin, input);
      if (return_condition && return_condition.value()(input)) {
        return std::nullopt;
      }
      number = parse::Parse<T>(input);
      if (validator && !validator.value()(number)) {
        throw exceptions::invalid_input("invalid number input");
      }
      break;
    } catch (const std::exception& e) {
      if (on_error) {
        on_error.value()(e);
      }
    }
  }
  return number;
}

}  // namespace ravesli_cpp_practice::utils::input_number

#endif  // !RAVESLI_CPP_PRACTICE_UTILS_INPUT_NUMBER_HPP