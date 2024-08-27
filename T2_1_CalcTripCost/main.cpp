/*
Задание №1

Напишите программу вычисления стоимости поездки на автомобиле на дачу (туда и
обратно). Исходными данными являются:
- расстояние до дачи (в км);
- литраж бензина, который потребляет автомобиль на 100 км пробега;
- цена одного литра бензина.

Пример результата выполнения программы:

Расстояние до дачи (км): 67
Расход бензина (литров на 100 км пробега): 8.5
Цена литра бензина (у.е.): 50
Поездка на дачу и обратно обойдется в 569.5 у.е.
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