// TP 2022/2023: LV 8, Zadatak 6
#include <cmath>
#include <iostream>

template <typename TipElemenata> struct Cvor {
  TipElemenata element;
  Cvor *veza;
};

template <typename TipElemenata>
Cvor<TipElemenata> *KreirajPovezanuListu(TipElemenata zavrsni) {
  Cvor<TipElemenata> *pocetak = nullptr;
  Cvor<TipElemenata> *prethodni = nullptr;

  for (;;) {
    TipElemenata n;
    std::cin >> n;
    if (n == zavrsni)
      break;
    Cvor<TipElemenata> *novi = new Cvor<TipElemenata>{n, nullptr};
    if (pocetak == nullptr)
      pocetak = novi;
    else
      prethodni->veza = novi;
    prethodni = novi;
  }
  return pocetak;
}

template <typename TipElemenata>
int BrojElemenata(Cvor<TipElemenata> *pocetak) {
  int brojEl = 0;

  while (pocetak != nullptr) {
    brojEl++;
    pocetak = pocetak->veza;
  }
  return brojEl;
}

template <typename TipElemenata>
TipElemenata SumaElemenata(Cvor<TipElemenata> *pocetak) {
  TipElemenata suma = TipElemenata();
  while (pocetak != nullptr) {
    suma += pocetak->element;
    pocetak = pocetak->veza;
  }
  return suma;
}

template <typename TipElemenata>
int BrojVecihOd(Cvor<TipElemenata> *pocetak, TipElemenata prag) {
  if (pocetak == nullptr)
    return 0;
  int broj = 0;
  while (pocetak != nullptr) {
    if (pocetak->element > prag) {
      broj++;
    }
    pocetak = pocetak->veza;
  }
  return broj;
}

template <typename TipElemenata> void UnistiListu(Cvor<TipElemenata> *pocetak) {
  if (pocetak == nullptr)
    return;

  while (pocetak != nullptr) {
    Cvor<TipElemenata> *pom = pocetak;
    pocetak = pocetak->veza;
    delete pom;
  }
}

int main() {
  std::cout << "Unesite slijed brojeva (0 za kraj): ";
  Cvor<double> *pocetak = KreirajPovezanuListu(0.0);

  int n = BrojElemenata(pocetak);
  double suma = SumaElemenata(pocetak);
  double arit = suma / n;
  int br = BrojVecihOd(pocetak, arit);

  std::cout << "U slijedu ima " << br
            << " brojeva vecih od njihove aritmeticke sredine" << std::endl;

  UnistiListu(pocetak);

  return 0;
}
