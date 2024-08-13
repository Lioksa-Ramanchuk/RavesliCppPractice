/*
«адание є2

Ќапишите программу, котора€ определ€ет минимальное число в последовательности
положительных чисел, которую ввел пользователь. ≈сли в последовательности есть
отрицательные числа, то вы должны сообщить об этом пользователю и предложить
повторить ввод еще раз.
*/

#include <format>
#include <iostream>
#include <string>
#include <vector>

#include "../Utils/parse.hpp"
#include "get_min_of_positives.hpp"

using namespace ravesli_cpp_practice;
using namespace ravesli_cpp_practice::t1_2_get_min_of_positives;

template<typename T> requires std::integral<T> || std::floating_point<T>
void EnterPositiveNumbersSequence(std::vector<T>& numbers);

int main() {
  std::vector<double> numbers;
  EnterPositiveNumbersSequence(numbers);
  
  std::cout << '\n';

  if (numbers.empty()) {
    std::cout << "No valid numbers were entered." << '\n';
    return 0;
  }

  std::cout << "The entered sequence: ";
  std::cout << numbers[0];
  for (size_t i = 1, n = numbers.size(); i < n; ++i) {
    std::cout << ", " << numbers[i];
  }
  std::cout << '\n';
  std::cout << "The minimal positive number in the sequence: "
            << GetMinOfPositives(numbers) << '\n';

  return 0;
}

template<typename T> requires std::integral<T> || std::floating_point<T>
void EnterPositiveNumbersSequence(std::vector<T>& numbers) {
  constexpr auto ERROR_FORMAT{"Error: {}"};
  constexpr auto INVALID_INPUT_ERROR_MESSAGE{"the entered value is invalid"};
  constexpr auto OUT_OF_RANGE_ERROR_MESSAGE{
      "the entered value is too large or too small"};

  std::string input;
  std::cout << "Enter a sequence of positive numbers (press <Enter> to finish):"
            << '\n';
  while (true) {
    std::cout << "> ";
    getline(std::cin, input);
    if (input.empty()) {
      break;
    }

    try {
      T number = utils::parse<T>(input);
      if constexpr (std::floating_point<T>) {
        if (std::isnan(number) || std::isinf(number)) {
          throw std::invalid_argument(INVALID_INPUT_ERROR_MESSAGE);
        }
      }

      if (number <= 0) {
        throw std::out_of_range(OUT_OF_RANGE_ERROR_MESSAGE);
      }

      numbers.push_back(number);
      continue;
    } catch (const std::invalid_argument&) {
      std::cerr << std::format(ERROR_FORMAT, INVALID_INPUT_ERROR_MESSAGE);
    } catch (const std::out_of_range&) {
      std::cerr << std::format(ERROR_FORMAT, OUT_OF_RANGE_ERROR_MESSAGE);
    }
    std::cout << ". Try again, please." << '\n';
  }
}