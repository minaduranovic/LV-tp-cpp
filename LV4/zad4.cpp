// TP 2022/2023: LV 4, Zadatak 4
#include <cmath>
#include <iostream>
template<typename Tip>
 void UnosBroja(std::string promt, std::string greska, Tip&prvi_broj){
    for(;;){
     std::cout<<promt;
     std::cin>>prvi_broj;
     //da li je ostalo ista u spremniku da nije enter
     if (!std::cin || std::cin.peek()!='\n') {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
    std::cout<<greska<<std::endl;
  }else break;
    }
 }

int main() {
    double x,m;
    int n,a;
  UnosBroja("Unesite bazu: ", "Neispravan unos, pokusajte ponovo...",x);
  UnosBroja("Unesite cjelobrojni eksponent: ", "Neispravan unos, pokusajte ponovo...",n);
  double rez = 1.0;
  m=x;
  a=n;
  if(n<0){ 
    m=1/x;
    a=-n;
    }
  for(int i=0; i<a; i++){
    rez*=m;
}
std::cout<<x<<" na "<<n<<" iznosi "<<rez;
    return 0;
  }
