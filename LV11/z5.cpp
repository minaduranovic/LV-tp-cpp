// TP 2022/2023: LV 11, Zadatak 5
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

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

class Liga {
  std::vector<std::unique_ptr<Tim>>timovi;

public:
  explicit Liga();
  explicit Liga(std::initializer_list<Tim> lista_timova);
  ~Liga();
  Liga(const Liga &l);
  Liga(Liga &&l);
  Liga &operator=(const Liga &l);
  Liga &operator=(Liga &&l);
  void DodajNoviTim(const char ime_tima[]);
  void RegistrirajUtakmicu(const char tim1[], const char tim2[], int rezultat_1,
                           int rezultat_2);
  void IspisiTabelu();
};
int main() {

//   Liga liga;
//   liga.DodajNoviTim("Borac");
//   liga.DodajNoviTim("Celik");
//   liga.DodajNoviTim("Jedinstvo");
//   liga.DodajNoviTim("Sarajevo");
//   liga.DodajNoviTim("Zeljeznicar");
//   liga.DodajNoviTim("Zrinjski");

//   while (true) {
//     liga.IspisiTabelu();
//     std::string tim1, tim2;
//     std::cout << "Unesite ime prvog tima (ENTER za kraj): ";
//     std::getline(std::cin, tim1);
//     if (tim1.length()==0)  break;
//     std::cout << "Unesite ime drugog tima: ";
//     std::getline(std::cin, tim2);
//     int golovi1, golovi2;
//     std::cout << "Unesite broj postignutih golova za oba tima: ";
//     std::cin >> golovi1 >> golovi2;
//     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//     try {
//       liga.RegistrirajUtakmicu(tim1.c_str(), tim2.c_str(), golovi1, golovi2);
//     } catch (const std::exception &e) {
//       std::cout << e.what() << std::endl;
//       continue;
//     }
//   }

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
  if (broj_datih < 0 || broj_primljenih < 0)  throw std::range_error("Neispravan broj golova");
  Tim::broj_primljenih += broj_primljenih;
  Tim::broj_datih += broj_datih;
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
            << std::setw(4) << broj_datih << std::setw(4) << broj_primljenih
            << std::setw(4) << broj_poena << std::endl;
}

Liga::Liga()  { }

Liga::Liga(std::initializer_list<Tim> lista_timova) {
  for ( auto tim : lista_timova) {
    DodajNoviTim(tim.DajImeTima());
  }
}

Liga::~Liga() { }

Liga::Liga(const Liga& l) {
  for ( auto& tim : l.timovi) {
    timovi.push_back(std::make_unique<Tim>(*tim));
  }
}
Liga::Liga(Liga &&l)  {
     timovi=std::move(l.timovi);
}

Liga& Liga::operator=(Liga &&l) {
    timovi = std::move(l.timovi);
  return *this;
}

Liga& Liga::operator=(const Liga& l) {
  if (this != &l) {
    std::vector<std::unique_ptr<Tim>> novi_timovi;
    for (const auto& tim : l.timovi) {
      novi_timovi.push_back(std::make_unique<Tim>(*tim));
    }
    timovi = std::move(novi_timovi);
  }
  return *this;
}
void Liga::DodajNoviTim(const char ime_tima[]) {
  for (const auto& tim : timovi) {
    if (strcmp(tim->DajImeTima(), ime_tima) == 0) {
      throw std::logic_error("Tim vec postoji");
    }
  }
  if (strlen(ime_tima) > 20) {
    throw std::range_error("Predugacko ime tima");
  }
  timovi.push_back(std::make_unique<Tim>(ime_tima));
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[],
                               int rezultat_1, int rezultat_2) {
  int itim1 = -1;
  int itim2 = -1;
  int i = 0;
  for (const auto &tim : timovi) {
    if (strcmp(tim->DajImeTima(), tim1) == 0) {
      itim1 = i;
    }
    if (strcmp(tim->DajImeTima(), tim2) == 0) {
      itim2 = i;
    }
    i++;
  }

  if (itim1 == -1 || itim2 == -1) {
    throw std::logic_error("Tim nije nadjen");
  }
  timovi[itim1]->ObradiUtakmicu(rezultat_1, rezultat_2);
  timovi[itim2]->ObradiUtakmicu(rezultat_2, rezultat_1);
}
void Liga::IspisiTabelu() {
 std::sort(timovi.begin(), timovi.end(),
            [](const std::unique_ptr<Tim> &t1, const std::unique_ptr<Tim> &t2) {
              if (t1->DajBrojPoena() != t2->DajBrojPoena()) {
                return t1->DajBrojPoena() > t2->DajBrojPoena();
              } else if (t1->DajGolRazliku() != t2->DajGolRazliku()) {
                return t1->DajGolRazliku() > t2->DajGolRazliku();
              } else {
                return strcmp(t1->DajImeTima(), t2->DajImeTima()) < 0;
              }
            });

 for (int i = 0; i < timovi.size(); i++) {
    timovi[i]->IspisiPodatke();
  }
}
