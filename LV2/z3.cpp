// TP 2022/2023: LV 2, Zadatak 3
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
    char zagrada = '(', zarez = ',', zagrada2 = ')';
    std::cout << "Z_" << i + 1 << " =  ";
    std::cin >> zagrada >> re >> zarez >> im >> zagrada2;
    z = std::complex<double>(re, im);
    paralelna += (1. / z);
  }
  paralelna = 1. / paralelna;
  std::cout << std::endl
            << "Paralelna veza ovih elemenata ima impedansu Z_ = " << paralelna
            << ".";

  return 0;
}
