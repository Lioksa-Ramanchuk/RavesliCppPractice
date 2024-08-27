/*
������� �3

�������� ���������, ������� ����������� � ������������ ����� ������ � �����
������� ��������������� �������� ������� ����. � ������, ���� ������������
������ ������������ �����, ��������� ������ ������� ��������� �� ������.

������ ���������� ���������� ���������:

������� ����� ������ (����� �� 1 �� 12): 12
����
*/

#include <iostream>
#include <optional>
#include <string>

#include "../Utils/constants.hpp"
#include "../Utils/input_number.hpp"
#include "get_season_by_month_number.hpp"

using namespace ravesli_cpp_practice;

using t1_3_get_season_by_month_number::GetSeasonByMonthNumber;
using utils::input_number::InputNumber;
using utils::constants::MIN_MONTH_NUMBER;
using utils::constants::MAX_MONTH_NUMBER;

std::optional<int> EnterMonthNumber();

int main() {
  auto month_number = EnterMonthNumber();
  if (!month_number.has_value()) {
    return 0;
  }

  std::cout << "The season for month " << month_number.value() << " is "
            << GetSeasonByMonthNumber(month_number.value()) << "." << '\n';

  return 0;
}

std::optional<int> EnterMonthNumber() {
  std::cout << "Enter a month number from 1 to 12 (or press <Enter> to exit):"
            << '\n';
  return InputNumber<double>(
      [](double value) {
        return MIN_MONTH_NUMBER<> <= value && value <= MAX_MONTH_NUMBER<>;
      },
      [](const std::exception&) {
        std::cerr << "Error: "
                  << "the entered value is invalid"
                  << ". Try again, please." << '\n';
      });
}