// TP 2022/2023: LV 6, Zadatak 5
#include <deque>
#include <iostream>
#include <memory>
#include <new>
#include <vector>


template <typename T> auto KreirajDinamickuKopiju2D(T &matrica) {
  int n = matrica.size();
  using elemt =  typename std::remove_reference<decltype(matrica[0][0])>::type;
  elemt **kopija;
  try {
    kopija = new elemt *[n];
    try {
      for (int i = 0; i < n; ++i) {
        int m = matrica[i].size();
        kopija[i] = new elemt[m];

        for (int j = 0; j < m; ++j) {
          kopija[i][j] = matrica[i][j];
        }
      }
    } catch (std::bad_alloc e) {
      for (int i = 0; i < n; ++i) {
        delete[] kopija[i];
      }
      delete[] kopija;
      throw e;
    }
  } catch (std::bad_alloc e) {
    throw e;
  }

  return kopija;
}

int main() {
  int n;
  std::cout << "Unesite broj redova kvadratne matrice: ";
  std::cin >> n;
try{
  std::vector<std::deque<int>> matrica(n, std::deque<int>(n));

  std::cout << "Unesite elemente matrice: ";
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> matrica[i][j];
    }
  }

  int **dinamicka_kopija = nullptr;

  try {
    dinamicka_kopija = KreirajDinamickuKopiju2D(matrica);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        std::cout << dinamicka_kopija[i][j] << " ";
      }
      std::cout << std::endl;
    }

  }
  catch (std::bad_alloc &e) {
    std::cout << "Nedovoljno memorije!\n";
  }

  if (dinamicka_kopija) {

    for (int i = 0; i < n; ++i) {
      delete[] dinamicka_kopija[i];
    }
    delete[] dinamicka_kopija;
  }
}catch(std::bad_alloc&e){
    std::cout<<"Nedovoljno memorije";
}
  return 0;
}
