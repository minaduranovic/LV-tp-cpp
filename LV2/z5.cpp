// TP 2022/2023: LV 2, Zadatak 5
#include <cmath>
#include <complex>
#include <iostream>

int main() {
  std::complex<double> paralelna = 0;

  int n;

  std::cout << "Unesite broj elemenata: " << std::endl;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    double re, fi;

    std::cout << "Z" << i + 1 << " = ";
    std::cin >> re;
    std::cout << "fi" << i + 1 << " =  " << std::endl;
    std::cin >> fi;
    fi = fi / 180 * (4 * atan(1));
    std::complex<double> z = std::polar(re, fi);
    paralelna += (1. / z);
  }
  paralelna = 1. / paralelna;

  std::cout << std::endl
            << "Paralelna veza ovih elemenata ima Z = " << abs(paralelna)
            << " i fi = " << arg(paralelna) * 180 / (4 * atan(1)) << ".";

  return 0;
}
