// TP 2022/2023: LV 10, Zadatak 1
#include <cmath>
#include <iostream>
#include <stdexcept>


class StedniRacun {
  double stanje;

public:
  StedniRacun(double trenutno = 0) {
    if (trenutno < 0)
      throw std::logic_error("Nedozvoljeno pocetno stanje");
    stanje = trenutno;
  };
  void Ulozi(double iznos) {
    if (iznos < 0 && std::abs(iznos) > stanje)
      throw std::logic_error("Transakcija odbijena");
    stanje += iznos;
  };
  void Podigni(double iznos) {
    if (iznos > stanje)
      throw std::logic_error("Transakcija odbijena");
    stanje -= iznos;
  };
  double const DajStanje() { return stanje; };
  void ObracunajKamatu(double stopa) {
    if (stopa < 0)
      throw std::logic_error("Nedozvoljena kamatna stopa");
    stanje = stanje * (1 + (stopa / 100));
  }
};
int main() {

    StedniRacun stedniRacun(1000);
    std::cout  << stedniRacun.DajStanje() << std::endl;

    stedniRacun.Ulozi(500);
    std::cout<< stedniRacun.DajStanje() << std::endl;

    stedniRacun.Podigni(200);
    std::cout << stedniRacun.DajStanje() << std::endl;

    stedniRacun.ObracunajKamatu(2.5);
    std::cout<< stedniRacun.DajStanje() << std::endl;
    stedniRacun.Podigni(2000);  
 

  return 0;
}

