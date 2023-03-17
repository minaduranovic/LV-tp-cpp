// TP 2022/2023: LV 2, Zadatak 1
#include <cmath>
#include <iostream>
#include <vector>

bool DaLiJeProst(int n) {

  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return false;
    }
  }
  if (n <= 0 || n == 1) {
    return false;
  }
  return true;
}
std::vector<int> ProstiBrojeviUOpsegu(int a, int b) {
  std::vector<int> prosti;
  int n = b - a;
  for (int i = 0; i <= n; i++) {
    if (DaLiJeProst(a) == true) {
      prosti.push_back(a);
    }
    a++;
  }

  return prosti;
}

int main() {
  int a, b;
  std::cout << "Unesite pocetnu i krajnju vrijednost: ";
  std::cin >> a >> b;
  std::vector<int> niz = ProstiBrojeviUOpsegu(a, b);

  if (niz.size() == 0) {
    std::cout << "Nema prostih brojeva u rasponu od " << a << " do " << b
              << "!";
  } else {
    std::cout << "Prosti brojevi u rasponu od " << a << " do " << b << " su: ";
    for (int i = 0; i < niz.size(); i++) {
      if (i != niz.size() - 1) {
        std::cout << niz.at(i) << ", ";
      } else {
        std::cout << niz.at(i) << " ";
      }
    }
  }
  return 0;
}
