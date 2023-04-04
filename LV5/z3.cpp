//TP 2022/2023: LV 5, Zadatak 3
#include <iostream>
#include <cmath>
#include<algorithm>

int broj_cifara( int n){
    if (n/10==0) return 1;
    return 1+broj_cifara(n/10);
}
bool potpun_kv(int n){
    if (sqrt(n)-int(sqrt(n))==0) return true;
    return false;
}
bool manji(int x, int y){
   return  broj_cifara(x)<broj_cifara(y);
}
void unos( int & n){
    std::cin>>n;
}
void ispis(int n){
    if (broj_cifara(n)!=3 ){
    std::cout<<n<< " ";
    }
}
int main ()
{

int n, niz[1000], niz2[1000];
std::cout<<"Unesite broj elemenata (max. 1000): ";
std::cin>>n;
std::cout<<"Unesite elemente: ";
std::for_each(niz, niz+n, unos);
std::cout<<"Najveci element niza je "<<*std::max_element(niz,niz+n)<<std::endl;
int min =*std::min_element(niz,niz+n);
std::cout<<"Najmanji element niza se pojavljuje "<< std::count(niz, niz+n, min)<<" puta u nizu"<<std::endl;
std::cout<<"U nizu ima " <<std::count_if(niz, niz+n, potpun_kv) <<" brojeva koji su potpuni kvadrati"<<std::endl;
std::cout<<"Prvi element sa najmanjim brojem cifara je "<<*std::min_element(niz, niz+n, manji)<<std::endl;
std::cout<<"Elementi koji nisu trocifreni su: ";
std::for_each(niz, niz+n, ispis);
	return 0;
}
