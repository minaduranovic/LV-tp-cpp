// TP 2022/2023: LV 9, Zadatak 4
#include <iomanip>
#include <iostream>
#include <stdexcept>

class Sat {
  int sati, minute, sekunde;

  void normal() {
    int ukupno = sati * 3600 + minute * 60 + sekunde;
    if (ukupno < 0)
      ukupno = 86400 - ((-ukupno) % 86400);
    else
      ukupno = ukupno % 86400;

    sati = (ukupno / 3600) % 24;
    minute = (ukupno / 60) % 60;
    sekunde = ukupno % 60;
  }

public:
  static bool DaLiJeIspravno(int sati, int minute, int sekunde) {
    return (sati >= 0 && sati <= 23) && (minute >= 0 && minute <= 59) &&
           (sekunde >= 0 && sekunde <= 59);
  }

  void Postavi(int sati, int minute, int sekunde) {
    if (DaLiJeIspravno(sati, minute, sekunde) == false)
      throw std::domain_error("Neispravno vrijeme");
    Sat::sati = sati;
    Sat::minute = minute;
    Sat::sekunde = sekunde;
  }

  void PostaviNormalizirano(int sati, int minute, int sekunde) {
    this->sati = sati;
    this->minute = minute;
    this->sekunde = sekunde;
    normal();
  }

  Sat &Sljedeci() {
    sekunde++;
    normal();
    return *this;
  }

  Sat &Prethodni() {
    if (sekunde == 0) {
      if (minute == 0) {
        sati = (sati - 1 + 24) % 24;
        minute = 59;
        sekunde = 59;
      } else {
        minute--;
        sekunde = 59;
      }
    } else {
      sekunde--;
    }
    return *this;
  }

  Sat &PomjeriZa(int brSek) {
    if (brSek >= 0) {
      sekunde += brSek;
      normal();
    } else {
      while (brSek != 0) {
        if (sekunde >= -brSek) {
          sekunde += brSek;
          break;
        } else {
          brSek += sekunde;
          sekunde = 60;
          if (minute == 0) {
            minute = 59;
            sati = (sati - 1 + 24) % 24;
          } else {
            minute--;
          }
        }
      }
      normal();
    }
    return *this;
  }

  void Ispisi() const {
    std::cout << std::setw(2) << std::setfill('0') << sati << ":"
              << std::setw(2) << std::setfill('0') << minute << ":"
              << std::setw(2) << std::setfill('0') << sekunde << std::endl;
  }

  int DajSate() const { return sati; }
  int DajMinute() const { return minute; }
  int DajSekunde() const { return sekunde; }

  friend int BrojSekundiIzmedju(const Sat &s1, const Sat &s2);

  static int Razmak(const Sat &s1, const Sat &s2) {
    return (s1.sati * 3600 + s1.minute * 60 + s1.sekunde) -
           (s2.sati * 3600 + s2.minute * 60 + s2.sekunde);
  }
};

int BrojSekundiIzmedju(const Sat &s1, const Sat &s2) {
  return (s1.sati * 3600 + s1.minute * 60 + s1.sekunde) -
         (s2.sati * 3600 + s2.minute * 60 + s2.sekunde);
}

int main() {

    Sat s;
    s.Postavi(12, 48, 59);
    s.Ispisi();
    s.Sljedeci().Sljedeci().Ispisi();
    s.Prethodni().Ispisi();
    s.PomjeriZa(-5).Ispisi();
    s.PostaviNormalizirano(25, 150, 290);
    s.Ispisi();

    Sat s1, s2;
    s1.Postavi(12, 30, 45);
    s2.Postavi(10, 20, 30);

    int razmak1 = BrojSekundiIzmedju(s1, s2);
    int razmak2 = Sat::Razmak(s1, s2);

    std::cout << razmak1 << std::endl;
    std::cout << razmak2 << std::endl;



  return 0;
}