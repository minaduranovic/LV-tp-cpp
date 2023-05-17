// TP 2022/2023: LV 10, Zadatak 4
#include <cmath>
#include <iomanip>
#include <iostream>


const double pi = 4 * atan(1);
class Ugao {
  double radijani;

  void opseg() {
    while (radijani >= 2 * pi) {
      radijani -= 2 * pi;
    }
    while (radijani < 0) {
      radijani += 2 * pi;
    }
  }

public:
  Ugao(double radijani = 0) {
    Ugao::radijani = radijani;
    opseg();
  };

  Ugao(int stepeni, int minute, int sekunde) {
    radijani = (stepeni + minute / 60.0 + sekunde / 3600) * pi / 180;
    opseg();
  }

  void Postavi(double radijani) {
    this->radijani = radijani;
    opseg();
  }
  void Postavi(int stepeni, int minute, int sekunde) {
    radijani = (stepeni + minute / 60 + sekunde / 3600) * pi / 180;
    opseg();
  }
  double DajRadijane() const { return radijani; };

  void OcitajKlasicneJedinice(int &stepeni, int &minute, int &sekunde) const {

    double ukupnoS = radijani * 180 / pi;
    stepeni = static_cast<int>(ukupnoS);
    double cast1 = (ukupnoS - stepeni) * 60;
    minute = static_cast<int>(cast1);
    double cast2 = (cast1 - minute) * 60;
    sekunde = static_cast<int>(cast2); //1e-10
  }
  int DajStepene() const {
    int stepeni, minute, sekunde;
    OcitajKlasicneJedinice(stepeni, minute, sekunde);
    return stepeni;
  }
  int DajMinute() const {
    int stepeni, minute, sekunde;
    OcitajKlasicneJedinice(stepeni, minute, sekunde);
    return minute;
  }
  int DajSekunde() const {
    int stepeni, minute, sekunde;
    OcitajKlasicneJedinice(stepeni, minute, sekunde);
    return sekunde;
  }
  void Ispisi() const {
    std::cout << std::fixed << std::setprecision(5) << radijani << std::endl;
  }
  void IspisiKlasicno() const {
    int stepeni, minute, sekunde;
    OcitajKlasicneJedinice(stepeni, minute, sekunde);
    std::cout << stepeni << "deg " << minute << "min " << sekunde << "sec"
              << std::endl;
  }
  Ugao &SaberiSa(const Ugao &u) {
    radijani += u.radijani;
    opseg();
    return *this;
  }
  Ugao &PomnoziSa(double x) {
    radijani *= x;
    opseg();
    return *this;
  }
  friend Ugao ZbirUglova(const Ugao &u1, const Ugao &u2) {
    return Ugao(u1.radijani + u2.radijani);
  }
  friend Ugao ProduktUglaSaBrojem(const Ugao &u, double x) {
    return Ugao(u.radijani * x);
  }
};
int main() {
  Ugao u1 = 2;
  u1.Ispisi();
  u1.IspisiKlasicno();
  int stepeni, minute, sekunde;
  u1.OcitajKlasicneJedinice(stepeni, minute, sekunde);
  std::cout << stepeni << " " << minute << " " << sekunde << std::endl;
  int stepeniU1 = u1.DajStepene();
  int minuteU1 = u1.DajMinute();
  int sekundeU1 = u1.DajSekunde();
  std::cout << stepeniU1 << "  " << minuteU1 << " " << sekundeU1 << std::endl;
  Ugao u2(180, 30, 0);
  u2.Ispisi();
  u2.IspisiKlasicno();
  Ugao u3 = ZbirUglova(u1, u2);
  u3.Ispisi();
  u3.IspisiKlasicno();
  Ugao u4 = ProduktUglaSaBrojem(u1, 2.5);
  u4.Ispisi();
  u4.IspisiKlasicno();
  u1.SaberiSa(u2);
  u1.Ispisi();
  u1.IspisiKlasicno();
  u2.PomnoziSa(0.5);
  u2.Ispisi();
  u2.IspisiKlasicno();

  return 0;
}
