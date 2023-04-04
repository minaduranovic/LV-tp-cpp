// TP 2022/2023: LV 5, Zadatak 4
#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>



bool troc(double x){
    return log10(fabs(x))>2 && log10(fabs(x))<4;
}
int main() {
  std::deque<int> niz1;
  int n;
  std::deque<int>::iterator it1 = niz1.begin();
  std::cout << "Unesite broj elemenata: ";
  std::cin >> n;
  niz1.resize(n);
  std::cout << "Unesite elemente: ";
  std::for_each(it1, it1 + n, [](int &x) { std::cin >> x; });
  std::cout << "Najveci element deka je " << *std::max_element(it1, it1 + n)
            << std::endl;
  int min = *std::min_element(it1, it1 + n);
  std::cout << "Najmanji element deka se pojavljuje "
            << std::count(it1, it1 + n, min) << " puta u deku" << std::endl;
  std::cout << "U deku ima "
            << std::count_if(it1, it1 + n,
                             [](int x) {
                               if (sqrt(x) - int(sqrt(x)) == 0)
                                 return true;
                               return false;
                             })
            << " brojeva koji su potpuni kvadrati" << std::endl;
  std::cout << "Prvi element sa najmanjim brojem cifara je "
            << *std::min_element(
                   it1, it1 + n,
                   [](int x, int y) { return int(log10(std::fabs(x))) +1 < int(log10(std::fabs(y))+1); })
            << std::endl;
  std::cout << "Elementi koji nisu trocifreni su: ";
  std::for_each(it1, it1 + n, [](int n) {
    if (int(log10(std::fabs(n))+1) != 3) {
      std::cout << n << " ";
    }
  });
  return 0;
}
