// //Napišite program koji traži da se sa tastature unesu tri realna broja 𝑎, 𝑏 i 𝑐, i koji ispisuje da li ta tri
// broja mogu biti stranice nekog trougla. Podsjetimo se da za stranice trougla mora vrijediti uvjet da
// su sve pozitivne i da je zbir dužina ma koje dvije stranice veći od dužine treće stranice. Ukoliko
// uneseni brojevi mogu predstavljati dužine stranica trougla, treba izračunati njegov obim, površinu i
// najmanji ugao, a zatim ispisati izračunate vrijednosti obima, površine i najmanjeg ugla, pri čemu
// ugao trea ispisati u stepenima, minutama i sekundama. Za računanje površine trougla koristite
// poznatu Heronovu formulu prema kojoj je P =√ ( 𝑎)( 𝑏)( 𝑐) gdje je = (𝑎 + 𝑏 + 𝑐)/2, a
// za računanje ugla koristite kosinusnu teoremu prema kojoj je 𝑐
//  = 𝑎
//  +𝑏
//  2𝑎𝑏 cos γ (i analogno
// tome za preostale kombinacije stranica i uglova). Računajte da 1 radijan ima 180/π stepeni, dok
// vrijednost π možete računati po formuli π = 4 ∙ arctg 1 (predmetni nastavnik ne želi da vidi da neko
// misli da je π = 3.14, to mu pokvari dan). Ukoliko uneseni brojevi ne mogu predstavljati dužine
// stranica trougla, treba ispisati odgovarajući komentar. Dijalozi koje formira program trebaju
// izgledati poput sljedećih (zanemarite eventualne probleme sa padežima i ostalom gramatikom):

// TP 2016/2017: Tutorijal 1, Zadatak 2
#include <cmath>
#include <iostream>

int main() {
  double a, b, c;
  int flag = 1;
  std::cout << "Unesite tri broja: ";
  std::cin >> a >> b >> c;
  if (a + b <= c || a + c <= b || b + c <= a || a <= 0 || b <= 0 || c <= 0) {
    std::cout << "Ne postoji trougao cije su duzine stranica " << a << ", " << b
              << " i " << c << "!";
    flag = 0;
  }
  double o = a + b + c;
  double s = o / 2;
  double p = std::sqrt(s * (s - a) * (s - b) * (s - c));
  double ugaoA = (acos((b * b + c * c - a * a) / (2 * b * c)) * 180 )/ (4*atan(1));
  double ugaoB = (acos((a * a + c * c - b * b) / (2 * a * c)) * 180 )/ (4*atan(1));
  double ugaoC = (acos((a * a + b * b - c * c) / (2 * a * b)) * 180) /(4*atan(1));

  if (flag == 1) {
    std::cout << "Obim trougla sa duzinama stranica " << a << ", " << b << " i "
              << c << " iznosi " << o << "." << std::endl;
    std::cout << "Njegova povrsina iznosi " << p << "." << std::endl;
    if (ugaoA <= ugaoB && ugaoA <= ugaoB) {
      std::cout << "Njegov najmanji ugao ima " << int(ugaoA) << " stepeni, "
                << int((ugaoA - (int)ugaoA) * 60) << " minuta"
                << " i "
                << int((((ugaoA - (int)ugaoA) * 60) -
                     (int)((ugaoA - (int)ugaoA) * 60)) *
                    60) 
                << " sekundi." << std::endl;
    }
    else if (ugaoB <= ugaoA && ugaoB<=ugaoC){
        std::cout << "Njegov najmanji ugao ima " << int(ugaoB) << " stepeni, "
                << int((ugaoB - (int)ugaoB) * 60) << " minuta"
                << " i "
                << int((((ugaoB - (int)ugaoB) * 60) -
                     (int)((ugaoB - (int)ugaoB) * 60)) *
                    60) 
                << " sekundi." << std::endl;
    }
    else if (ugaoC<=ugaoA && ugaoC<=ugaoB){
        std::cout << "Njegov najmanji ugao ima " << int(ugaoC) << " stepeni, "
                << int((ugaoC - (int)ugaoC) * 60) << " minuta"
                << " i "
                << int((((ugaoC - (int)ugaoC) * 60) -
                     (int)((ugaoC - (int)ugaoC) * 60)) *
                    60) 
                << " sekundi." << std::endl;
    }
  }
  return 0;
}