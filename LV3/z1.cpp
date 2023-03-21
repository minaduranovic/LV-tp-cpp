// TP 2022/2023: LV 3, Zadatak 1
#include <cmath>
#include <iostream>
#include <vector>


bool parna(int broj) {
  int broj2 = broj, suma = 0;
  if (broj2 < 0)
    broj2 = -broj2;
  while (broj2 != 0) {
    suma += broj2 % 10;
    broj2 = broj2 / 10;
  }
  if (suma % 2 == 0) {
    return true;
  } else
    return false;
}
std::vector<int> IzdvojiElemente(std::vector<int> v, bool logic) {
  std::vector<int> novi;
  if (logic == true) {
    for (int x : v) {
      if (parna(x) == true) {
        novi.push_back(x);
      }
    }
  } else if (logic == false) {
    for (int x : v) {
      if (parna(x) == false) {
        novi.push_back(x);
      }
    }
  }
  return novi;
}
int main() {
  int n;
  std::vector<int> a,b,c;
//   std::vector<int> b;
//   std::vector<int> c;
  int broj;
  std::cout << "Koliko zelite unijeti elemenata: ";
  std::cin >> n;
  if (n == 0) {
    std::cout << "Broj elemenata mora biti veci od 0!";
    return 0;
  }
  std::cout << "Unesite elemente: ";
  for (int i = 0; i < n; i++) {
    std::cin >> broj;
    a.push_back(broj);
  }
  b = IzdvojiElemente(a, true);
  c = IzdvojiElemente(a, false);

  for (int x : b) {
    std::cout << x << " ";
  }
  std::cout << std::endl;

  for (int y : c) {
    std::cout << y << " ";
  }

  return 0;
}

