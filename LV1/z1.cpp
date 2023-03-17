// //Neka je dat bazen oblika kvadra dimenzije 𝑎 × 𝑏 × 𝑐 i keramičke pločice oblika kvadrata dimenzija
// 𝑑 × 𝑑. Napišite program koji prvo zahtijeva od korisnika da unese dužinu, širinu i dubinu bazena (tj.
// 𝑎, 𝑏 i 𝑐) u metrima, kao i širinu keramičke pločice 𝑑 u centimetrima. Program zatim treba da ispita
// da li je bazen moguće popločati takvim pločicama, a da se pri tome niti jedna pločica ne treba lomiti
// (debljinu pločice zanemariti). Ukoliko to nije moguće, treba ispisati odgovarajući komentar.
// Ukoliko jeste, treba ispisati koliko je pločica potrebno za popločavanje (naravno, popločavaju se
// zidovi i dno bazena). Slijede primjeri dva dijaloga između programa i korisnika. Radi autotestiranja,
// dijalozi bi trebali izgledati tačno kako je prikazano, uključujući i mjesta gdje se prelazi u novi red i
// prazne redove, samo se brojevi koje unosi korisnik mogu razlikovati (iza posljednje rečenice
// također je potreban prelazak u novi red). Afrikati poput “č”, “ć” itd. se ne koriste u ispisu zbog
// činjenice da nije sasvim jednostavno podesiti da se oni ispravno prikazuju (to će vrijediti i ubuduće).

#include <cmath>
#include <iostream>
// TP 2016/2017: Tutorijal 1, Zadatak 2
int main() {
  int a, b, c, d;
  std::cout << "Unesite duzinu, sirinu i dubinu bazena u metrima: ";
  std::cin >> a >> b >> c;
  std::cout << "Unesite sirinu plocice u centimetrima: " << std::endl;
  std::cin >> d;

  int p = (a * b + 2 * b * c + 2 * a * c) * 10000;
  int ploc = d * d;
  int broj = p / ploc;
  int p1 = a * b * 10000;
  int p2 = a * c * 10000;
  int p3 = b * c * 10000;
  int broj1 = p1 / ploc;
  int broj2 = p2 / ploc;
  int broj3 = p3 / ploc;
  if ((broj * ploc < p) || broj1 * ploc < p1 || broj2 * ploc < p2 ||
      broj3 * ploc < p3 || (a*100)%d!=0 || (b*100)%d!=0 || (c*100)%d!=0) {
    std::cout << "Poplocavanje bazena dimenzija " << a << "x" << b << "x" << c
              << "m sa plocicama dimenzija " << d << "x" << d << "cm"
              << std::endl
              << " nije izvodljivo bez lomljenja plocica!" << std::endl;

  } else {
    std::cout << "Za poplocavanje bazena dimenzija " << a << "x" << b << "x"
              << c << "m sa plocicama dimenzija " << d << "x" << d << "cm"
              << std::endl
              << "potrebno je " << broj << " plocica." << std::endl;
  }
  return 0;
}