// TP 2022/2023: LV 7, Zadatak 9
#include <cmath>
#include <functional>
#include <iostream>


std::function<double(double)> plus2(double x) {
    
  return [x](double y) { return x + y; };
}

std::function<std::function<double(double)>(double)> plus3(double x) {

  return [x](double y) { return [x, y](double z) { return x + y + z; }; };
}

int main() {
  auto f = plus2(1);
  auto g = plus3(1);

  std::cout << f(2) << std::endl;
  std::cout << g(2)(3);

  return 0;
}
