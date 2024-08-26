#ifndef RAVESLI_CPP_PRACTICE_T2_2_CALC_COST_WITH_DISCOUNT_HPP
#define RAVESLI_CPP_PRACTICE_T2_2_CALC_COST_WITH_DISCOUNT_HPP

#include <map>

namespace ravesli_cpp_practice::t2_2_calc_cost_with_discount {

std::pair<double, double> CalcCostWithDiscount(double cost,
                            const std::map<double, double>& discounts) {
  auto discount = 0.0;
  for (auto it = discounts.crbegin(); it != discounts.crend(); ++it) {
    if (cost > it->first) {
      discount = it->second;
      break;
    }
  }
  return {cost * (1 - discount), discount};
}

}  // namespace ravesli_cpp_practice::t2_2_calc_cost_with_discount

#endif  // !RAVESLI_CPP_PRACTICE_T2_2_CALC_COST_WITH_DISCOUNT_HPP