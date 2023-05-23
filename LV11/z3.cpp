// TP 2022/2023: LV 11, Zadatak 3
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>


class Tim {
  char ime_tima[20];
  int broj_odigranih;
  int broj_pobjeda;
  int broj_nerijesenih;
  int broj_poraza;
  int broj_datih;
  int broj_primljenih;
  int broj_poena;

public:
  Tim(const char ime[]);
  void ObradiUtakmicu(int broj_datih, int broj_primljenih);
  const char *DajImeTima() const { return ime_tima; }
  int DajBrojPoena() const { return broj_poena; }
  int DajGolRazliku() const { return broj_datih - broj_primljenih; }
  void IspisiPodatke() const;
};

int main() {

  Tim tim("Real Madrid");
  tim.ObradiUtakmicu(2, 1);
  tim.IspisiPodatke();
  std::cout << tim.DajImeTima() << std::endl;
  std::cout << tim.DajBrojPoena() << std::endl;
  std::cout << tim.DajGolRazliku() << std::endl;

  return 0;
}

Tim::Tim(const char ime[]) {

  if (strlen(ime) > 20) throw std::range_error("Predugacko ime tima");

  strcpy(ime_tima, ime);
  broj_datih = 0;
  broj_nerijesenih = 0;
  broj_pobjeda = 0;
  broj_poena = 0;
  broj_poraza = 0;
  broj_primljenih = 0;
  broj_odigranih = 0;
}
void Tim::ObradiUtakmicu(int broj_datih, int broj_primljenih) {
    
  if (broj_datih < 0 || broj_primljenih < 0) throw std::range_error("Neispravan broj golova");

  this->broj_primljenih += broj_primljenih;
  this->broj_datih += broj_datih;
  broj_odigranih++;

  if (broj_datih > broj_primljenih) {
    broj_pobjeda++;
    broj_poena += 3;
  } else if (broj_datih == broj_primljenih) {
    broj_nerijesenih++;
    broj_poena += 1;
  } else {
    broj_poraza++;
  }
}
void Tim::IspisiPodatke() const {
  std::cout << std::left << std::setw(20) << ime_tima << std::right
            << std::setw(4) << broj_odigranih << std::setw(4) << broj_pobjeda
            << std::setw(4) << broj_nerijesenih << std::setw(4) << broj_poraza
            << std::setw(4) << Tim::broj_datih << std::setw(4)
            << Tim::broj_primljenih << std::setw(4) << broj_poena << std::endl;
}
