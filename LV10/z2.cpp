// TP 2022/2023: LV 10, Zadatak 2
#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>

class Krug {
  double poluprecnik;

public:
  explicit Krug(double r) {
    if (r <= 0)
      throw std::domain_error("Neispravan poluprecnik");
    poluprecnik = r;
  };
  void Postavi(double r) {
    if (r <= 0)
      throw std::domain_error("Neispravan poluprecnik");
    poluprecnik = r;
  };
  double DajObim() const { return 2 * poluprecnik * 4 * atan(1); };
  double DajPoluprecnik() const { return poluprecnik; };
  double DajPovrsinu() const {
    return poluprecnik * poluprecnik * 4 * atan(1);
  };
  void Skaliraj(double faktor) {
    if (faktor <= 0)
      throw std::domain_error("Neispravan faktor skaliranja");
    poluprecnik *= faktor;
  };
  void Ispisi() const {
    std::cout << std::fixed << std::setprecision(5) << "R=" << DajPoluprecnik()
              << " O=" << DajObim() << " P=" << DajPovrsinu();
  }
};
class Valjak {
  Krug baza;
  double visina;

public:
  Valjak(double r, double H) : baza(r) {
    if (H <= 0)
      throw std::domain_error("Neispravna visina");
    visina = H;
  };
  void Postavi(double r, double h) {
    if (r <= 0)
      throw std::domain_error("Neispravan poluprecnik");
    if (h <= 0)
      throw std::domain_error("Neispravna visina");
    baza.Postavi(r);
    visina = h;
  }
  Krug DajBazu() const { return baza; };

  double DajPoluprecnikBaze() const { return baza.DajPoluprecnik(); }

  double DajVisinu() const { return visina; }

  double DajPovrsinu() const {
    return 2 * baza.DajPovrsinu() + baza.DajObim() * visina;
  }
  double DajZapreminu() const { return baza.DajPovrsinu() * visina; }

  void Skaliraj(double faktor) {
    if (faktor <= 0)
      throw std::domain_error("Neispravan faktor skaliranja");
    baza.Skaliraj(faktor);
    visina *= faktor;
  }
  void Ispisi() const {
    std::cout << std::fixed << std::setprecision(5)
              << "R=" << DajPoluprecnikBaze() << " H=" << visina
              << " P=" << DajPovrsinu() << " V=" << DajZapreminu();
  }
};

int main() {

  Krug k(5);
  k.Ispisi();
  std::cout << std::endl;
  k.Postavi(7);
  k.Ispisi();
  std::cout << std::endl;
  double obim = k.DajObim();
  double poluprecnik = k.DajPoluprecnik();
  double povrsina = k.DajPovrsinu();
  std::cout << obim << std::endl;
  std::cout << poluprecnik << std::endl;
  std::cout << povrsina << std::endl;
  k.Skaliraj(1.5);
  k.Ispisi();
  std::cout << std::endl;
  Valjak v(4, 6);
  v.Ispisi();
  std::cout << std::endl;
  v.Postavi(3, 5);
  v.Ispisi();
  std::cout << std::endl;
  Krug baza = v.DajBazu();
  double poluprecnikBaze = v.DajPoluprecnikBaze();
  double visina = v.DajVisinu();
  double povrsinaValjka = v.DajPovrsinu();
  double zapremina = v.DajZapreminu();
  std::cout << poluprecnikBaze << std::endl;
  std::cout << visina << std::endl;
  std::cout << povrsinaValjka << std::endl;
  std::cout << zapremina << std::endl;
  v.Skaliraj(0.8);
  v.Ispisi();
  std::cout << std::endl;

  return 0;
}
