//TP 2022/2023: LV 5, Zadatak 6
#include <algorithm>
#include <iostream>
#include <cmath>
#include<vector>

int suma_cif(int n)
{
    if (abs(n) == 0)
       return 0;
    return (abs(n) % 10 + suma_cif(abs(n) / 10));
}
void unos( int & n){
    std::cin>>n;
}
void ispis( int  n){
    std::cout<<n<<" ";
}
bool f(int a, int b){
    int suma1 = suma_cif(a);
    int suma2 = suma_cif(b);
    if (suma1 == suma2) {
        return a<b ;
    } else  {
        return suma1<suma2;
    }
}

int main ()
{
std::vector<int> vektor;
std::cout<<"Unesite broj elemenata: ";
int n;
std::cin>>n;
vektor.resize(n);
std::cout<<"Unesite elemente: ";
std::for_each(vektor.begin(), vektor.end(), unos);
std::sort(vektor.begin(), vektor.end(), f);
std::cout<<"Niz sortiran po sumi cifara glasi: ";
std::for_each(vektor.begin(), vektor.end(), ispis);
std::cout<<std::endl<<"Unesite broj koji trazite: ";
int broj;
std::cin>>broj;

std::vector<int>::iterator it=std::find(vektor.begin(),vektor.end(), broj);
if (it==vektor.end()) std::cout<<"Trazeni broj ne nalazi se u nizu!";
else{
int ind=it-vektor.begin();
std::cout<<"Trazeni broj nalazi se na poziciji "<<ind;
}
	return 0;
}
