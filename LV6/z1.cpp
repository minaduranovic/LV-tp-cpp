//TP 2022/2023: LV 6, Zadatak 1
#include <exception>
#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>

template<typename t>
t* GenerirajStepeneDvojke(int n){
    if (n<=0) throw std::domain_error("Broj elemenata mora biti pozitivan");
    t* niz=nullptr;
    try{
        niz=new t[n];
    } catch(...){
        throw std::runtime_error("Alokacija nije uspjela");
    }
    t tr=1;
    for (int i=0; i<n; i++){
        niz[i]=tr;
        if (i<n-1 && tr>std::numeric_limits<t>::max()/2){
            delete[] niz;
            throw std::overflow_error("Prekoracen dozvoljeni opseg");
        }
        tr*=2;
    }
    return niz;
}
int main ()
{
    int n;
    std::cout<<"Koliko zelite elemenata: ";
    std::cin>>n;
    try{
        auto niz=GenerirajStepeneDvojke<unsigned long long int>(n);
       for (int i=0; i<n; i++){
           std::cout<<niz[i]<<" ";
       }
       delete[] niz;
    }catch(std::exception &e){
        std::cout<<"Izuzetak: "<<e.what();
    }


	return 0;
}
