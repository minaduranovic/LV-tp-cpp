// TP 2022/2023: LV 9, Zadatak 3
#include <cmath>
#include <iostream>

class Vektor3d {
  double niz[3];
  mutable int brojIspisa = 0;

public:
  void Postavi(double x, double y, double z) {
    niz[0] = x;
    niz[1] = y;
    niz[2] = z;
  }
  Vektor3d &PostaviX(const double &x1) {
    niz[0] = x1;
    return *this;
  }
  Vektor3d &PostaviY(const double &y1) {
    niz[1] = y1;
    return *this;
  }
  Vektor3d &PostaviZ(const double &z1) {
    niz[2] = z1;
    return *this;
  }
  void Ocitaj(double &x, double &y, double &z) const {
    x = niz[0];
    y = niz[1];
    z = niz[2];
  }
  void Ispisi() const {
    std::cout << "{" << niz[0] << "," << niz[1] << "," << niz[2] << "}";
    brojIspisa++;
  }

  int DajBrojIspisa() const { return brojIspisa; }

  double DajX() const { return niz[0]; }
  double DajY() const { return niz[1]; }
  double DajZ() const { return niz[2]; }
  double DajDuzinu() const {
    return std::sqrt(niz[0] * niz[0] + niz[1] * niz[1] + niz[2] * niz[2]);
  }
  Vektor3d &PomnoziSaSkalarom(double s) {
    niz[0] *= s;
    niz[1] *= s;
    niz[2] *= s;
    return *this;
  }
  Vektor3d &SaberiSa(const Vektor3d &v) {
    niz[0] += v.niz[0];
    niz[1] += v.niz[1];
    niz[2] += v.niz[2];
    return *this;
  }
  friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2) {
    Vektor3d v3;
    v3.niz[0] = v1.niz[0] + v2.niz[0];
    v3.niz[1] = v1.niz[1] + v2.niz[1];
    v3.niz[2] = v1.niz[2] + v2.niz[2];
    return v3;
  }
};

int main() {
  Vektor3d v1, v2;
  v1.PostaviX(1).PostaviY(2).PostaviZ(3);
  v2.Postavi(4, 5, 6);
  double x1, y1, z1, x2, y2, z2;
  v1.Ocitaj(x1, y1, z1);
  v2.Ocitaj(x2, y2, z2);
  std::cout << x1 << y1 << z1 << std::endl;
  std::cout << x2 << y2 << z2 << std::endl;
  v1.Ispisi();
  std::cout << std::endl;
  v2.Ispisi();
  std::cout << std::endl;
  double v1x, v1y, v1z;
  double v2x, v2y, v2z;
  v1.DajX();
  v1.DajY();
  v1.DajZ();
  v2.DajX();
  v2.DajY();
  v2.DajZ();
  double duz1 = v1.DajDuzinu();
  double duz2 = v2.DajDuzinu();
  std::cout << duz1 << "   " << duz2 << "\n";
  v1.PomnoziSaSkalarom(2);
  v2.PomnoziSaSkalarom(2);
  v1.Ispisi();
  std::cout << std::endl;
  v2.Ispisi();
  std::cout << std::endl;

  auto v3 = v1.SaberiSa(v2);
  v3.Ispisi();
  std::cout << std::endl;
  auto v3p = v1.SaberiSa(v2);
  v3p.Ispisi();

  return 0;
}
