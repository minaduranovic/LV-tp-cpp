// TP 2022/2023: LV 7, Zadatak 6
#include <cmath>
#include <iostream>
#include <list>

template <typename tip> 
void SortirajListu(std::list<tip> &lista) {
  // std::list<tip> nova(lista);
  auto p1 = lista.begin();
  auto p2 = lista.end();
  while (p1 != p2) {
    auto min = p1;
    auto temp =++p1;
    p1--;
    while (temp != p2) {
      if (*temp < *min) {
        min = temp;
      }
      temp++;
    }
    std::swap(*p1, *min);
    p1++;
  }
}
int main() {
  std::cout << "Koliko ima elemenata: ";
  int n;
  std::cin >> n;
  std::list<int> lista;
  std::cout << "\nUnesite elemente: ";
  int i = 0;
  while (i != n) {
    int x;
    std::cin >> x;
    lista.push_back(x);
    i++;
  }
  SortirajListu(lista);
  std::cout << "\nSortirana lista: ";
  for (auto x : lista)
    std::cout << x << " ";

  return 0;
}
