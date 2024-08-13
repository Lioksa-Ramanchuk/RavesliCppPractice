/*
Задание №3

Напишите программу, которая запрашивает у пользователя номер месяца и затем
выводит соответствующее название времени года. В случае, если пользователь
введет недопустимое число, программа должна вывести сообщение об ошибке.

Пример результата выполнения программы:

Введите номер месяца (число от 1 до 12): 12
Зима
*/

#include <format>
#include <iostream>
#include <string>

#include "../Utils/constants.hpp"
#include "../Utils/parse.hpp"
#include "get_season_by_month_number.hpp"

using namespace ravesli_cpp_practice;
using namespace ravesli_cpp_practice::t1_3_get_season_by_month_number;

bool EnterMonthNumber(int& month);

int main() {
  auto month = 0;
  if (!EnterMonthNumber(month)) {
    return 0;
  }

  std::cout << std::format("The season for month {} is {}.", month,
                           GetSeasonByMonthNumber(month))
            << '\n';
    
  return 0;
}

bool EnterMonthNumber(int& month) {
  constexpr auto ERROR_FORMAT{"Error: {}"};
  constexpr auto INVALID_INPUT_ERROR_MESSAGE{"the entered value is invalid"};
  constexpr auto OUT_OF_RANGE_ERROR_MESSAGE{
      "the entered value is too large or too small"};

  std::string input;
  std::cout << "Enter a month number from 1 to 12 (or press <Enter> to exit):"
            << '\n';
  while (true) {
    std::cout << "> ";
    getline(std::cin, input);
    if (input.empty()) {
      return false;
    }

    try {
      month = utils::parse<int>(input);
      if (month < utils::MIN_MONTH_NUMBER<> ||
          month > utils::MAX_MONTH_NUMBER<>) {
        throw std::out_of_range(OUT_OF_RANGE_ERROR_MESSAGE);
      }
      break;
    } catch (const std::invalid_argument&) {
      std::cerr << std::format(ERROR_FORMAT, INVALID_INPUT_ERROR_MESSAGE);
    } catch (const std::out_of_range&) {
      std::cerr << std::format(ERROR_FORMAT, OUT_OF_RANGE_ERROR_MESSAGE);
    }
    std::cout << ". Try again, please." << '\n';
  }

  return true;
}