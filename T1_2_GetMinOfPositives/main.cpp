/*
«адание є2

Ќапишите программу, котора€ определ€ет минимальное число в последовательности
положительных чисел, которую ввел пользователь. ≈сли в последовательности есть
отрицательные числа, то вы должны сообщить об этом пользователю и предложить
повторить ввод еще раз.
*/

#include <iostream>
#include <string>
#include <vector>

#include "../Utils/input_number.hpp"
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
  std::cout << "Enter a sequence of positive numbers (press <Enter> to finish):"
            << '\n';
  while (true) {
    auto number = utils::InputNumber<double>(
        [](double value) { return value > 0; },
        [](const std::exception&) {
          std::cerr << "Error: "
                    << "the entered value is invalid"
                    << ". Try again, please." << '\n';
        },
        [](const std::string& input) { return input.empty(); });
    if (number.has_value()) {
      numbers.push_back(number.value());
      continue;
    }
    break;
  }
}