// TP 2022/2023: LV 9, Zadatak 1
#include <cmath>
#include <iostream>

class Vektor3d {
  double x, y, z;

public:
  void Postavi(double x, double y, double z) {
    Vektor3d::x = x;
    Vektor3d::y = y;
    Vektor3d::z = z;
  }
  Vektor3d &PostaviX(const double &x1) {
    x = x1;
    return *this;
  }
  Vektor3d &PostaviY(const double &y1) {
    y = y1;
    return *this;
  }
  Vektor3d &PostaviZ(const double &z1) {
    z = z1;
    return *this;
  }
  void Ocitaj(double &x, double &y, double &z) const {
    x = Vektor3d::x;
    y = Vektor3d::y;
    z = Vektor3d::z;
  }
  void Ispisi() const { std::cout << "{" << x << "," << y << "," << z << "}"; }
  double DajX() const { return x; }
  double DajY() const { return y; }
  double DajZ() const { return z; }
  double DajDuzinu() const { return std::sqrt(x * x + y * y + z * z); }
  Vektor3d &PomnoziSaSkalarom(double s) {
    x *= s;
    y *= s;
    z *= s;
    return *this;
  }
  Vektor3d &SaberiSa(const Vektor3d &v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
  }
  friend Vektor3d ZbirVektora(const Vektor3d &v1, const Vektor3d &v2) {
    Vektor3d v3;
    v3.x = v1.x + v2.x;
    v3.y = v1.y + v2.y;
    v3.z = v1.z + v2.z;
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
