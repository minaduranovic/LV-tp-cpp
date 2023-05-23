// TP 2022/2023: LV 11, Zadatak 4
#include <algorithm>
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

class Liga {
  int broj_timova = 0;
  const int max_br_timova;
  Tim **timovi = nullptr;

public:
  explicit Liga(int velicina_lige);
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

  Liga liga(6);
  liga.DodajNoviTim("Borac");
  liga.DodajNoviTim("Celik");
  liga.DodajNoviTim("Jedinstvo");
  liga.DodajNoviTim("Sarajevo");
  liga.DodajNoviTim("Zeljeznicar");
  liga.DodajNoviTim("Zrinjski");

  while (true) {
    liga.IspisiTabelu();
    std::string tim1, tim2;
    std::cout << "Unesite ime prvog tima (ENTER za kraj): ";
    std::getline(std::cin, tim1);
    if (tim1.length() == 0) {
      break;
    }
    std::cout << "Unesite ime drugog tima: ";
    std::getline(std::cin, tim2);
    int gol1, gol2;
    std::cout << "Unesite broj postignutih golova za oba tima: ";
    std::cin >> gol1 >> gol2;
    std::cin.ignore(1000, '\n');

    try {
      liga.RegistrirajUtakmicu(tim1.c_str(), tim2.c_str(), gol1, gol2);
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
      continue;
    }
  }

  return 0;
}

Tim::Tim(const char ime[]) {

  if (strlen(ime) > 20)
    throw std::range_error("Predugacko ime tima");

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

  if (broj_datih < 0 || broj_primljenih < 0)
    throw std::range_error("Neispravan broj golova");
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
            << std::setw(4) << broj_datih << std::setw(4) << broj_primljenih
            << std::setw(4) << broj_poena << std::endl;
}

Liga::Liga(int velicina_lige) : max_br_timova(velicina_lige) {
  if (velicina_lige < 0)
    throw std::range_error("Nesaglasni kapaciteti liga");
  timovi = new Tim *[velicina_lige];
}

Liga::Liga(std::initializer_list<Tim> lista_timova)
    : max_br_timova(lista_timova.size()) {

  if (lista_timova.size() > max_br_timova)
    throw std::range_error("Nesaglasni kapaciteti liga");

  timovi = new Tim *[max_br_timova];
  for (auto tim : lista_timova) {
    DodajNoviTim(tim.DajImeTima());
  }
}
Liga::~Liga() {
  for (int i = 0; i < max_br_timova; i++) {
    delete timovi[i];
  }
  delete[] timovi;
}
Liga::Liga(const Liga &l)
    : max_br_timova(l.max_br_timova), broj_timova(l.broj_timova) {
  timovi = new Tim *[max_br_timova];
  for (int i = 0; i < l.broj_timova; i++) {
    timovi[i] = new Tim(*(l.timovi[i]));
  }
}
Liga::Liga(Liga &&l)
    : max_br_timova(l.max_br_timova), broj_timova(l.broj_timova),
      timovi(l.timovi) {
  l.timovi = nullptr;
}

Liga &Liga::operator=(const Liga &l) {
  if (this != &l) {
    if (max_br_timova != l.max_br_timova)
      throw std::logic_error("Nesaglasni kapaciteti liga");

    Tim **novi = new Tim *[max_br_timova];
    for (int i = 0; i < l.broj_timova; i++) {
      novi[i] = new Tim(*(l.timovi[i]));
    }
    for (int i = 0; i < broj_timova; i++) {
      delete timovi[i];
    }
    delete[] timovi;
    broj_timova = l.broj_timova;
    timovi = novi;
  }
  return *this;
}
Liga &Liga::operator=(Liga &&l) {
  if (max_br_timova != l.max_br_timova) {
    throw std::logic_error("Nesaglasni kapaciteti liga");
  }
  broj_timova = l.broj_timova;
  timovi = l.timovi;
  l.timovi = nullptr;
  return *this;
}
void Liga::DodajNoviTim(const char ime_tima[]) {

  if (broj_timova == max_br_timova)
    throw std::range_error("Liga popunjena");

  for (int i = 0; i < broj_timova; i++) {
    if (strcmp(timovi[i]->DajImeTima(), ime_tima) == 0)
      throw std::logic_error("Tim vec postoji");
  }
  if (strlen(ime_tima) > 20)
    throw std::range_error("Predugacko ime tima");

  timovi[broj_timova] = new Tim(ime_tima);
  broj_timova++;
}

void Liga::RegistrirajUtakmicu(const char tim1[], const char tim2[],
                               int rezultat_1, int rezultat_2) {
  int itim1 = -1;
  int itim2 = -1;
  int i;
  for (i = 0; i < broj_timova; i++) {
    if (strcmp(timovi[i]->DajImeTima(), tim1) == 0) {
      itim1 = i;
    }
    if (strcmp(timovi[i]->DajImeTima(), tim2) == 0) {
      itim2 = i;
    }
  }

  if (itim1 == -1 || itim2 == -1) {
    throw std::logic_error("Tim nije nadjen");
  }
  timovi[itim1]->ObradiUtakmicu(rezultat_1, rezultat_2);
  timovi[itim2]->ObradiUtakmicu(rezultat_2, rezultat_1);
}
void Liga::IspisiTabelu() {
  std::sort(timovi, timovi + broj_timova, [](const Tim *t1, const Tim *t2) {
    if (t1->DajBrojPoena() != t2->DajBrojPoena()) {
      return t1->DajBrojPoena() > t2->DajBrojPoena();
    } else if (t1->DajGolRazliku() != t2->DajGolRazliku()) {
      return t1->DajGolRazliku() > t2->DajGolRazliku();
    } else {
      return strcmp(t1->DajImeTima(), t2->DajImeTima()) < 0;
    }
  });
  for (int i = 0; i < broj_timova; i++) {
    timovi[i]->IspisiPodatke();
  }
}