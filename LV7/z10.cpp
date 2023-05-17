// TP 2022/2023: LV 7, Zadatak 10
#include <cmath>
#include <functional>
#include <iostream>

std::function<int(int)> IteriranaFunkcija(std::function<int(int)> f, int n) {
  if (n <= 0)
    return [](int x) { return x; };
  return [f, n](int x) {
    for (int i = 0; i < n; i++) {
      x = f(x);
    }
    return x;
  };
}

int main() {
  auto f = [](int x) { return x + 1; };
  auto g = IteriranaFunkcija(f, 10);
  std::cout << g(5);

  return 0;
}
