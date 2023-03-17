// TP 2022/2023: LV 2, Zadatak 2
#include <cmath>
#include <iostream>
#include <vector>

bool TestPerioda(std::vector<double> slijed, int p) {

  if (p >= slijed.size() || p == 0) {
    return false;
  }

  for (int i = 0; i < slijed.size() - p; i++) {
    if (slijed.at(i) != slijed.at(i + p)) {
      return false;
    }
  }

  return true;
}
int OdrediOsnovniPeriod(std::vector<double> slijed) {

  if (slijed.size() == 0) {
    return 0;
  }
  for (int i = 1; i <= slijed.size(); i++) {

    if (TestPerioda(slijed, i) == true) {
      return i;
    }
  }

  return 0;
}

int main() {
  double clan;
  std::vector<double> slijed;
  std::cout << "Unesite slijed brojeva (0 za kraj): ";

  do {
    std::cin >> clan;
    if (clan != 0) {
      slijed.push_back(clan);
    }
  } while (clan != 0);
  int period = OdrediOsnovniPeriod(slijed);
  if (period == 0) {
    std::cout << "Slijed nije periodican!";
  } else {
    std::cout << "Slijed je periodican sa osnovnim periodom " << period << ".";
  }
  return 0;
}
