// TP 2022/2023: LV 6, Zadatak 5
#include <deque>
#include <iostream>
#include <memory>
#include <new>
#include <vector>


template <typename T>
 auto KreirajDinamickuKopiju2D(T &matrica) {
  int n = matrica.size();
 int m = matrica[0].size();
  using elemt = typename std::remove_reference<decltype(matrica[0][0])>::type;
  elemt **kopija=nullptr ;
  
  try {
kopija = new elemt *[n]();

kopija[0]=new elemt[m*n];
    for (int i = 0; i < n; i++) {
   
      kopija[i] = kopija[0]+m*i;
      for (int j = 0; j < m; j++) {
        kopija[i][j] = matrica[i][j];
      }
    }
  } catch (std::bad_alloc) {
   delete[] kopija[0];
   delete[] kopija;
    throw;
  }

  return kopija;
}

int main() {
    try{
  int n;
  std::cout << "Unesite broj redova kvadratne matrice: ";
  std::cin >> n;

  std::vector<std::deque<int>> matrica(n, std::deque<int>(n));

  std::cout << "Unesite elemente matrice: ";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      std::cin >> matrica[i][j];
    }
  }

  int **dinamicka_kopija = nullptr;

  try {
    dinamicka_kopija = KreirajDinamickuKopiju2D(matrica);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        std::cout << dinamicka_kopija[i][j] << " ";
      }
      std::cout << std::endl;
    }

  }

  catch (std::bad_alloc &e) {
    std::cout << "Nedovoljno memorije!\n";
  }
      delete[] dinamicka_kopija[0];
    
    delete[] dinamicka_kopija;
    }catch(std::bad_alloc &e){
    std::cout<<"Nedovoljno memorije";
    }
  return 0;
}
