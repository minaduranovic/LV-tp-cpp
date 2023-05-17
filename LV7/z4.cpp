// TP 2022/2023: LV 7, Zadatak 4
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

  std::cout << "Unesite recenice: ";
  try {
    std::unique_ptr<tip[]> niz(new tip[n]);

    for (int i = 0; i < n; i++) {
      niz[i] = std::make_shared<std::string>();

      std::getline(std::cin, *niz[i]);
    }

    std::sort(niz.get(), niz.get() + n, [](tip &a, tip &b) { return *a < *b; });

    std::cout << std::endl << "Sortirane recenice: ";
    for (int i = 0; i < n; i++) {
      std::cout << *niz[i];
      std::cout << std::endl;
    }
  } catch (...) {
    std::cout << "\nProblemi s memorijom!";
    return 1;
  }

  return 0;
}
