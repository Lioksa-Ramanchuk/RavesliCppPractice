#ifndef RAVESLI_CPP_PRACTICE_T1_3_GET_SEASON_BY_MONTH_NUMBER_GET_SEASON_BY_MONTH_NUMBER_HPP
#define RAVESLI_CPP_PRACTICE_T1_3_GET_SEASON_BY_MONTH_NUMBER_GET_SEASON_BY_MONTH_NUMBER_HPP

#include <stdexcept>
#include <string>

namespace ravesli_cpp_practice::t1_3_get_season_by_month_number {

std::string GetSeasonByMonthNumber(int month) {
  if (month < 1 || month > 12) {
    throw std::invalid_argument("invalid month number");
  }

  constexpr const char* SEASONS[] = {"Winter", "Spring", "Summer", "Autumn"};
  return SEASONS[(month % 12) / 3];
}

}  // namespace ravesli_cpp_practice::t1_3_get_season_by_month_number

#endif  // !RAVESLI_CPP_PRACTICE_T1_3_GET_SEASON_BY_MONTH_NUMBER_GET_SEASON_BY_MONTH_NUMBER_HPP