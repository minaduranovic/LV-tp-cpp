// TP 2022/2023: LV 3, Zadatak 6
#include <cmath>
#include <iomanip>
#include <iostream>
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

std::vector<std::vector<int>> KroneckerovProizvod(std::vector<int> a,
                                                  std::vector<int> b) {
  std::vector<std::vector<int>> mat(a.size(), std::vector<int>(b.size()));

  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      mat[i][j] = (a[i] * b[j]);
    }
  }
  return mat;
}

int main() {
  int m, n;
  int broj;
  std::vector<int> v1;
  std::vector<int> v2;

  std::cout << "Unesite broj elemenata prvog vektora: ";
  std::cin >> m;
  std::cout << "Unesite elemente prvog vektora: ";
  for (int i = 0; i < m; i++) {
    std::cin >> broj;
    v1.push_back(broj);
  }
  std::cout << "Unesite broj elemenata drugog vektora: ";
  std::cin >> n;
  std::cout << "Unesite elemente drugog vektora: ";
  for (int i = 0; i < n; i++) {
    std::cin >> broj;
    v2.push_back(broj);
  }

  std::vector<std::vector<int>> mat = KroneckerovProizvod(v1, v2);
  int sirina = NajvecaSirina(mat) + 1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      std::cout << std::setw(sirina) << mat[i][j];
    }
    std::cout << std::endl;
  }

  return 0;
}
