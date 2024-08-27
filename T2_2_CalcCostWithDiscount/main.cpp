/*
Задание №2

Напишите программу вычисления стоимости покупки с учетом скидки. Скидка в 3%
предоставляется, если сумма покупки больше 500 долларов, в 5% — если сумма
покупки больше 1000 долларов.

Пример результата выполнения программы:

Введите сумму покупки: 640
Вам предоставляется скидка в 3%
Сумма с учетом скидки: 620.80 долларов.
*/

#include <format>
#include <iostream>
#include <map>

#include "../Utils/input_number.hpp"
#include "calc_cost_with_discount.hpp"

using namespace ravesli_cpp_practice;

using t2_2_calc_cost_with_discount::CalcCostWithDiscount;
using utils::input_number::InputNumber;

int main() {
  const std::map<double, double> kDiscounts{{500, 0.03}, {1000, 0.05}};

  std::cout << "Enter the purchase cost (in $):" << '\n';
  const auto kCost =
      InputNumber<double>([](double value) { return value >= 0; },
                          [](const std::exception&) {
                            std::cerr << "Error: "
                                      << "the entered value is invalid"
                                      << ". Try again, please." << '\n';
                          })
          .value();

  const auto kCostWithDiscount = CalcCostWithDiscount(kCost, kDiscounts);

  std::cout << '\n';
  std::cout << "Your discount: " << kCostWithDiscount.second * 100 << "%"
            << '\n';
  std::cout << std::format("The purchase cost with the discount: ${:.2f}",
                           kCostWithDiscount.first)
            << '\n';

  return 0;
}