// TP 2022/2023: LV 7, Zadatak 5
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>


int main() {
  std::cout << "Koliko zelite recenica: ";
  int n;
  std::cin >> n;
  std::cin.ignore();

  using tip = std::shared_ptr<std::string>;

  try {
    std::cout << "Unesite recenice: ";
    std::shared_ptr<tip[]> niz(new tip[n]{}, [](tip *p) { delete[] p; });

    try {
      for (int i = 0; i < n; i++) {

        niz.get()[i] = std::make_shared<std::string>();
        std::getline(std::cin, *niz[i]);
      }

      std::sort(niz.get(), niz.get() + n,
                [](tip &a, tip &b) { return *a < *b; });

      std::cout << std::endl << "Sortirane recenice: ";
      for (int i = 0; i < n; i++) {
        std::cout << *niz.get()[i];
        std::cout << std::endl;
      }
    } catch (...) {
      std::cout << "\nProblemi s memorijom!";
      return 1;
    }
  } catch (...) {
    std::cout << "\nProblemi s memorijom!";
    return 1;
  }

  return 0;
}
