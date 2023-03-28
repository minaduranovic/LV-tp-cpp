// TP 2022/2023: LV 4, Zadatak 1
#include <cmath>
#include <iostream>

long long int Cifre(long long int n, int &c_min, int &c_max) {
//   if (n < 0)  n = -n;
  if (n==0) {
    c_min=0 ;
    c_max=0;
    return 1;   
  }
int broj = 0;
  c_min = 9;
  c_max = 0;
  while (n != 0) {
    int c = n % 10;
    if (c<0) c=-c;
    if (c < c_min) c_min = c;
    if (c > c_max) c_max = c;
    n = n / 10;
    broj++;
  }
  if (broj==0) return 1;
  return broj;
}
int main() { 
long long int n;
int cmin, cmax, br;
std::cout<<"Unesite broj: ";
std::cin>>n;
br=Cifre(n, cmin, cmax);
std::cout<<"Broj "  << n<< " ima "<<br<<" cifara, najveca je "<<cmax<< " a najmanja "<<cmin <<".";
    return 0;
     }
