#ifndef RAVESLI_CPP_PRACTICE_UTILS_RANDOMIZER_HPP
#define RAVESLI_CPP_PRACTICE_UTILS_RANDOMIZER_HPP

#include <random>

namespace ravesli_cpp_practice::utils::randomizer {

class Randomizer {
 public:
  template <typename T = int>
    requires std::integral<T>
  static auto GenerateInt(T min_inclusive, T max_exclusive) {
    if (max_exclusive <= min_inclusive) {
      throw std::invalid_argument(
          "max_exclusive must be greater than min_inclusive");
    }
    std::uniform_int_distribution<T> dist(min_inclusive, max_exclusive - 1);
    return dist(engine_);
  }

  template <typename T = float>
    requires std::floating_point<T>
  static auto GenerateFloat(T min_inclusive, T max_exclusive) {
    if (max_exclusive <= min_inclusive) {
      throw std::invalid_argument(
          "max_exclusive must be greater than min_inclusive");
    }
    std::uniform_real_distribution<T> dist(min_inclusive, max_exclusive);
    return dist(engine_);
  }

  static auto GenerateBool() {
    std::bernoulli_distribution dist(0.5);
    return dist(engine_);
  }

 private:
  inline static thread_local std::mt19937 engine_{std::random_device{}()};
};

}  // namespace ravesli_cpp_practice::utils::randomizer

#endif  // !RAVESLI_CPP_PRACTICE_UTILS_RANDOMIZER_HPP