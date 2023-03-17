// Napišite program koji traži da se sa tastature unesu dva prirodna broja 𝑎 i 𝑏, ne veća od 9999 i pri
// čemu je 𝑎 < 𝑏, a koji zatim za sve prirodne brojeve u opsegu od 𝑎 do 𝑏 uključivo ispisuje tablicu
// njihovih kvadrata, kvadratnih korijena i prirodnih logaritama. Tačan izgled tablice vidljiv je iz
// dijaloga koji će biti prikazan. Uglavnom, kolona za prikaz brojeva široka je 9 polja. Brojevi se
// ispisuju poravnati ulijevo, pri čemu je prvo polje uvijek razmak. Kolone za prikaz kvadrata i
// korijena široke su 10 polja, dok je kolona za prikaz logaritama široka 11 polja. Kvadrati, korijeni i
// logaritmi se ispisuju poravnati udesno, pri čemu je posljednje polje uvijek razmak. Pored toga,
// korijeni se ispisuju fiksno na tri decimale, a logaritmi fiksno na pet decimala. Slijedi primjer kako
// treba izgledati dijalog između korisnika i programa:

// TP 2016/2017: LV 1, Zadatak 4
#include <cmath>
#include <iostream>

int main() {
  int suma = 0, broj1;
  double broj;

  for (;;) {
    std::cout << "Unesite prirodan broj ili 0 za kraj: ";
    std::cin >> broj;
    if (broj == 0 && std::cin) {
      std::cout << "Dovidjenja!";
      break;
    } else if (!std::cin) {
      std::cout << "Niste unijeli prirodan broj!" << std::endl;
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    } else if (broj < 0 || broj - static_cast<int>(broj) != 0) {
      std::cout << "Niste unijeli prirodan broj!" << std::endl;
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    } else if (std::cin) {
      broj1 = broj;
      int broj2 = broj;
      suma = 0;
      for (int i = 1; i < broj; i++) {
        if (broj2 % i == 0) {
          suma += i;
        }
      }
      if (suma == broj1) {
        std::cout << "Broj " << broj1 << " je savrsen!" << std::endl;
      } else if (suma > broj1) {
        std::cout << "Broj " << broj1 << " je obilan!" << std::endl;
      } else {
        std::cout << "Broj " << broj1 << " je manjkav!" << std::endl;
      }
    } else {
      std::cout << "Niste unijeli prirodan broj!" << std::endl;
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    }
  }
  return 0;
}