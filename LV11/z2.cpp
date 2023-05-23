//TP 2022/2023: LV 11, Zadatak 2
#include <cmath>
#include <iostream>
#include <stdexcept>

class StedniRacun {
  static int brojKreiranih;  
  static int brojAktivnih;  
  double stanje;

public:
  StedniRacun(double trenutno = 0) {
    if (trenutno < 0)
      throw std::logic_error("Nedozvoljeno pocetno stanje");
    stanje = trenutno;
    brojKreiranih++;        
    brojAktivnih++;        
  };

  StedniRacun(const StedniRacun& r) {
    stanje = r.stanje;
    brojKreiranih++;        
    brojAktivnih++;         
  }

  ~StedniRacun() {
    brojAktivnih--;        
  }

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

  double const DajStanje() const { return stanje; };

  void ObracunajKamatu(double stopa) {
    if (stopa < 0)
      throw std::logic_error("Nedozvoljena kamatna stopa");
    stanje = stanje * (1 + (stopa / 100));
  }

  static int DajBrojKreiranih() {
    return brojKreiranih;
  }

  static int DajBrojAktivnih() {
    return brojAktivnih;
  }
};

int StedniRacun::brojKreiranih = 0;
int StedniRacun::brojAktivnih = 0;

int main() {
StedniRacun s1, s2(100);
{ StedniRacun s3(50); } // Nakon "}", "s3" više ne postoji...
std::cout << StedniRacun::DajBrojKreiranih()
 << " " << StedniRacun::DajBrojAktivnih();
 return 0;
}
