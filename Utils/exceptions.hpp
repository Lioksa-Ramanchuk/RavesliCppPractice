#ifndef RAVESLI_CPP_PRACTICE_UTILS_EXCEPTIONS_HPP
#define RAVESLI_CPP_PRACTICE_UTILS_EXCEPTIONS_HPP

#include <stdexcept>
#include <string>

namespace ravesli_cpp_practice::utils::exceptions {

class invalid_input : public std::runtime_error {
 public:
  explicit invalid_input(const std::string& message)
      : std::runtime_error(message) {}
  explicit invalid_input(const char* message) : std::runtime_error(message) {}
};

}  // namespace ravesli_cpp_practice::utils::exceptions

#endif  // !RAVESLI_CPP_PRACTICE_UTILS_EXCEPTIONS_HPP