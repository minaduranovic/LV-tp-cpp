// TP 2022/2023: LV 7, Zadatak 8
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>


std::string IzvrniBezRazmaka(const std::string &s) {
  std::string novi;
  std::remove_copy(s.rbegin(), s.rend(), std::back_inserter(novi), ' ');
  return novi;
}
int main() {
  std::string s = "Evo pada kiša";
  auto novi = IzvrniBezRazmaka(s);
  std::cout << novi;

  return 0;
}
