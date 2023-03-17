// TP 2022/2023: LV 2, Zadatak 4
#include <cmath>
#include <complex>
#include <iostream>

int main() {
  std::complex<double> z;
  std::complex<double> paralelna = 0;
  int n;

  std::cout << "Unesite broj elemenata: " << std::endl;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    double re, im;
    std::cout << "R" << i + 1 << " = ";
    std::cin >> re;
    std::cout << "X" << i + 1 << " = " << std::endl;
    std::cin >> im;
    z = std::complex<double>(re, im);
    paralelna += (1. / z);
  }
  paralelna = 1. / paralelna;
  std::cout << std::endl
            << "Paralelna veza ovih elemenata ima R = " << paralelna.real()
            << " i X = " << paralelna.imag() << ".";

  return 0;
}
