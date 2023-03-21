//TP 2022/2023: LV 3, Zadatak 5

#include <cmath>
#include <iostream>
#include <deque>


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
std::deque<int> IzdvojiElemente(std::deque<int> v, bool logic) {
  std::deque<int> novi;
  if (logic == true) {
    for (int i=v.size()-1 ; i>=0; i--) {
      if (parna(v[i]) == true) {
        novi.push_front(v[i]);
      }
    }
  } else if (logic == false) {
   for (int i=v.size()-1 ; i>=0; i--) {
      if (parna(v[i]) == false) {
        novi.push_front(v[i]);
      }
    }
  }
  return novi;
}
int main() {
  int n;
  std::deque<int> a,b,c;

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

  for (int i = 0; i < b.size(); i++) {
    if (i == b.size() - 1) {
      std::cout << b[i];
    } else {
      std::cout << b[i] << ",";
    }
  }
  std::cout << std::endl;

  for (int i = 0; i < c.size(); i++) {
    if (i == c.size() - 1) {
      std::cout << c[i];
    } else {
      std::cout << c[i] << ",";
    }
  }
  return 0;
}

