#ifndef RAVESLI_CPP_PRACTICE_T2_3_PLAY_DIGIT_PLACE_GAME_HPP
#define RAVESLI_CPP_PRACTICE_T2_3_PLAY_DIGIT_PLACE_GAME_HPP

#include <array>
#include <format>
#include <iostream>
#include <string>

#include "../Utils/constants.hpp"
#include "../Utils/input_number.hpp"
#include "../Utils/math.hpp"
#include "../Utils/randomizer.hpp"
#include "../Utils/type_aliases.hpp"

namespace ravesli_cpp_practice::t2_3_digit_place_game {

using utils::constants::DEC_DIGITS_COUNT;
using utils::constants::MAX_DIGITS_COUNT;
using utils::input_number::InputNumber;
using utils::math::Pow;
using utils::randomizer::Randomizer;
using utils::type_aliases::uint8;
using utils::type_aliases::ullong;

template <int kDigitsCount>
  requires(1 <= kDigitsCount && kDigitsCount < MAX_DIGITS_COUNT<ullong>())
void PlayDigitPlaceGame() {
  constexpr ullong kUpperBound = Pow(10ULL, kDigitsCount);
  const auto kSecretNumber = Randomizer::GenerateInt<ullong>(0, kUpperBound);

  using DigitArray = std::array<uint8, kDigitsCount>;
  DigitArray secret_number_digits{};
  DigitArray guess_number_digits{};

  auto parse_digits = [](ullong number, DigitArray& digits) {
    for (auto i = digits.size(); i-- > 0ULL;) {
      digits[i] = static_cast<uint8>(number % 10ULL);
      number /= 10ULL;
    }
  };
  parse_digits(kSecretNumber, secret_number_digits);

  std::cout << std::format(
                   "An integer number from {} to {} is chosen! "
                   "Try to guess it! (Press <Enter> to exit.)",
                   0ULL, kUpperBound - 1ULL)
            << '\n'
            << '\n';

  std::array<uint8, DEC_DIGITS_COUNT<>>
      mismatched_secret_number_digits_occurrences{};
  std::array<uint8, DEC_DIGITS_COUNT<>>
      mismatched_guess_number_digits_occurrences{};

  ullong tries_count = 0;
  while (true) {
    std::cout << "(#" << ++tries_count << ") Your guess: ";
    const auto kGuess = InputNumber<ullong>(
        [kUpperBound](ullong value) { return value < kUpperBound; },
        [](const std::exception&) {
          std::cerr
              << "Error: the entered value is invalid. Try again, please: ";
        },
        [](const std::string& input) { return input.empty(); });
    if (!kGuess.has_value()) {
      std::cout << '\n';
      std::cout << "The guessed number: " << kSecretNumber << '\n';
      break;
    }

    parse_digits(kGuess.value(), guess_number_digits);

    int correct_digits_count = 0;
    int misplaced_digits_count = 0;

    mismatched_secret_number_digits_occurrences.fill(0);
    mismatched_guess_number_digits_occurrences.fill(0);

    for (int i = 0; i < kDigitsCount; ++i) {
      if (guess_number_digits[i] == secret_number_digits[i]) {
        ++correct_digits_count;
      } else {
        ++mismatched_secret_number_digits_occurrences[secret_number_digits[i]];
        ++mismatched_guess_number_digits_occurrences[guess_number_digits[i]];
      }
    }

    for (int i = 0; i < DEC_DIGITS_COUNT<>; ++i) {
      misplaced_digits_count +=
          std::min(mismatched_secret_number_digits_occurrences[i],
                   mismatched_guess_number_digits_occurrences[i]);
    }

    std::cout << "Correct digits number: "
              << correct_digits_count + misplaced_digits_count << '\n';
    std::cout << "Correctly placed digits number: " << correct_digits_count
              << '\n';
    if (correct_digits_count == kDigitsCount) {
      std::cout << '\n';
      std::cout << std::format("Congratulations! You guessed the number {}!",
                               kSecretNumber)
                << '\n';
      break;
    }

    std::cout << '\n';
  }
}

}  // namespace ravesli_cpp_practice::t2_3_digit_place_game

#endif  // !RAVESLI_CPP_PRACTICE_T2_3_PLAY_DIGIT_PLACE_GAME_HPP