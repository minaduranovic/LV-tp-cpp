// TP 2022/2023: LV 3, Zadatak 8
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>


std::string IzdvojiRijec(std::string recenica, int broj) {
  if (broj < 1) {
    throw std::range_error("Pogresan redni broj rijeci!");
  }
  int count = 0;
  std::string trenutna;
  for (int i = 0; i < recenica.length(); i++) {
    if (recenica[i] != ' ') {
      trenutna += recenica[i];
    }
    if (i == recenica.length() - 1 || recenica[i] == ' ') {
      if (trenutna.length() > 0) {
        count++;
        if (count == broj) {
          return trenutna;
        }
        trenutna = "";
      }
    }
  }
  throw std::range_error("Pogresan redni broj rijeci!");
}
int main() {
  int broj;
  std::string recenica;
  std::cout << "Unesite redni broj rijeci: ";
  std::cin >> broj;
  std::cin.ignore();
  std::cout << "Unesite recenicu: ";
  std::getline(std::cin, recenica);

  try {
    std::string rijec = IzdvojiRijec(recenica, broj);
    std::cout << "Rijec na poziciji " << broj << " je " << rijec;
  } catch (std::range_error &e) {
    std::cout << "IZUZETAK: " << e.what() << std::endl;
  }

  return 0;
}
