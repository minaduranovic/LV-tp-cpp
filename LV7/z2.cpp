// TP 2022/2023: LV 7, Zadatak 2
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>


int main() {
  std::cout << "Koliko zelite recenica: ";
  int n;
  std::cin >> n;
  std::cin.ignore();
  char **niz = nullptr;
  std::cout << "Unesite recenice: ";
  try {
    niz = new char *[n];
    int i = 0;
    try {
      while (i != n) {
        char pom[100];
        std::cin.getline(pom, sizeof(pom));

        niz[i] = new char[std::strlen(pom) + 1];

        std::strcpy(niz[i], pom);
        i++;
      }
    } catch (...) {
      for (int j = 0; j < i; j++) {
        delete[] niz[j];
      }
      delete[] niz;
      std::cout << "\nProblemi s memorijom!";
      return 1;
    }

    std::sort(niz, niz + n,
              [&](char *x, char *y) { return std::strcmp(x, y) < 0; });
    std::cout << std::endl << "Sortirane recenice: ";
    for (int i = 0; i < n; i++) {
      std::cout << niz[i];
      std::cout << std::endl;
    }
  } catch (...) {
    delete[] niz;
    std::cout << "\nProblemi s memorijom!";
    return 1;
  }
  for (int i = 0; i < n; i++) {
    delete[] niz[i];
  }
  delete[] niz;
  return 0;
}
