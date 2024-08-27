/*
������� �1

�������� ��������� ���������� ��������� ������� �� ���������� �� ���� (���� �
�������). ��������� ������� ��������:
- ���������� �� ���� (� ��);
- ������ �������, ������� ���������� ���������� �� 100 �� �������;
- ���� ������ ����� �������.

������ ���������� ���������� ���������:

���������� �� ���� (��): 67
������ ������� (������ �� 100 �� �������): 8.5
���� ����� ������� (�.�.): 50
������� �� ���� � ������� ��������� � 569.5 �.�.
*/

#include <format>
#include <iostream>

#include "../Utils/input_number.hpp"
#include "calc_trip_cost.hpp"

using namespace ravesli_cpp_practice;
using namespace ravesli_cpp_practice::t2_1_calc_trip_cost;

using utils::input_number::InputNumber;

int main() {
  const auto kIsNonNegative = [](double value) { return value >= 0; };
  const auto kProcessInvalidInput = [](const std::exception&) {
    std::cerr << "Error: "
              << "the entered value is invalid"
              << ". Try again, please." << '\n';
  };

  std::cout << "Enter the trip distance (in km):" << '\n';
  const auto kDistance_km =
      InputNumber<double>(kIsNonNegative, kProcessInvalidInput).value();

  std::cout << '\n';
  std::cout << "Enter the petrol consumption (in liters per 100 km):" << '\n';
  const auto kConsumption_l_per_km =
      InputNumber<double>(kIsNonNegative, kProcessInvalidInput).value() / 100;

  std::cout << '\n';
  std::cout << "Enter the petrol price (in CU per liter):" << '\n';
  const auto kPetrolPrice_cu_per_l =
      InputNumber<double>(kIsNonNegative, kProcessInvalidInput).value();

  std::cout << '\n';
  std::cout << std::format(
                   "The round trip cost: {:.2f} CU",
                   CalcRoundTripCost(kDistance_km, kConsumption_l_per_km,
                                     kPetrolPrice_cu_per_l))
            << '\n';

  return 0;
}