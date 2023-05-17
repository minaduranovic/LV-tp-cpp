// TP 2022/2023: LV 8, Zadatak 1
#include <cmath>
#include <iomanip>
#include <iostream>
#include <pthread.h>
#include <stdexcept>

struct Vrijeme {
  int sati;
  int minute;
  int sekunde;
};
void TestirajVrijeme(const Vrijeme &v) {
  if (v.minute < 0 || v.minute > 59 || v.sati < 0 || v.sati > 23 ||
      v.sekunde < 0 || v.sekunde > 59)
    throw std::domain_error("Neispravno vrijeme");
}
void IspisiVrijeme(const Vrijeme &v) {
  TestirajVrijeme(v);
  std::cout << std::setw(2) << std::setfill('0') << v.sati << ":"
            << std::setw(2) << std::setfill('0') << v.minute << ":"
            << std::setw(2) << std::setfill('0') << v.sekunde << std::endl;
}
Vrijeme SaberiVrijeme(const Vrijeme &v1, const Vrijeme &v2) {
  TestirajVrijeme(v1);
  TestirajVrijeme(v2);
  Vrijeme novo;

  novo.sekunde = v1.sekunde + v2.sekunde;
  novo.minute = v1.minute + v2.minute;
  novo.sati = v1.sati + v2.sati;

  if (novo.sekunde >= 60) {
    novo.sekunde -= 60;
    novo.minute++;
  }
  if (novo.minute >= 60) {
    novo.minute -= 60;
    novo.sati++;
  }
  if (novo.sati >= 24) {
    novo.sati -= 24;
  }
  return novo;
}
int main() {
  Vrijeme v1, v2;
  try {
    std::cout << "Unesite prvo vrijeme (h m s): ";
    std::cin >> v1.sati >> v1.minute >> v1.sekunde;
    TestirajVrijeme(v1);
  } catch (std::domain_error &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
  try {
    std::cout << "Unesite drugo vrijeme (h m s): ";
    std::cin >> v2.sati >> v2.minute >> v2.sekunde;
    TestirajVrijeme(v2);
  } catch (std::domain_error &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }

  try {
    std::cout << "Prvo vrijeme: ";
    IspisiVrijeme(v1);
    std::cout << "Drugo vrijeme: ";
    IspisiVrijeme(v2);

    Vrijeme novo = SaberiVrijeme(v1, v2);
    std::cout << "Zbir vremena: ";
    IspisiVrijeme(novo);

  } catch (const std::domain_error &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
