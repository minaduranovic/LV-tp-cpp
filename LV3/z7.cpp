// TP 2022/2023: LV 3, Zadatak 7
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

int count(int broj) {
  int count = 0;
  bool neg = false;
  if (broj < 0) {
    broj = -broj;
    neg = true;
  }
  if (broj == 0)
    return 1;
  while (broj != 0) {
    broj = broj / 10;
    count++;
  }
  if (neg == true)
    count++;
  return count;
}
int NajvecaSirina(std::vector<std::vector<int>> mat) {
  if (mat.size() == 0)
    return 0;
  int max = count(mat[0][0]);

  for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[i].size(); j++) {
      if (count(mat[i][j]) > max) {
        max = count(mat[i][j]);
      }
    }
  }
  return max;
}
std::vector<std::vector<int>> PascalovTrougao(int n) {
  if (n < 0) {
    throw std::domain_error("Broj redova ne smije biti negativan");
  }

  std::vector<std::vector<int>> mat(n);

  if (n == 0)
    return mat;

  for (int i = 0; i < n; i++) {
    mat[i].resize(i + 1);
    mat[i][0] = 1;
    mat[i][i] = 1;
    for (int j = 1; j < i; j++) {
      mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
    }
  }
  return mat;
}
int main() {
  int n;
  std::cout << "Unesite broj redova: ";
  std::cin >> n;
  auto mat = PascalovTrougao(n);
  int sirina = NajvecaSirina(mat) + 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      std::cout << std::setw(sirina) << mat[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}
