#ifndef RAVESLI_CPP_PRACTICE_T2_1_CALC_TRIP_COST_HPP
#define RAVESLI_CPP_PRACTICE_T2_1_CALC_TRIP_COST_HPP

namespace ravesli_cpp_practice::t2_1_calc_trip_cost {

double CalcTripCost(double distance, double consumption, double petrol_price) {
  return distance * consumption * petrol_price;
}

double CalcRoundTripCost(double distance, double consumption,
                         double petrol_price) {
  return CalcTripCost(distance, consumption, petrol_price) * 2;
}

}  // namespace ravesli_cpp_practice::t2_1_calc_trip_cost

#endif  // !RAVESLI_CPP_PRACTICE_T2_1_CALC_TRIP_COST_HPP