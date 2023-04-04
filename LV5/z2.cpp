//TP 2022/2023: LV 5, Zadatak 2
#include <algorithm>
#include <iostream>
#include <cmath>

template <typename iter_tip_1, typename iter_tip_2>
iter_tip_2 RazmijeniBlokove(iter_tip_1 pocetak, iter_tip_1 iza_kraja, iter_tip_2 odrediste){
    while (pocetak != iza_kraja){
       auto temp=*pocetak;
        *pocetak=*odrediste;
        *odrediste=temp;
        pocetak++;
        odrediste++;
    }
    return odrediste;
}
int main ()
{
int a[]={5,6,7,8};
int b[]={1,2,3,4};
RazmijeniBlokove(a, a+4, b);
std::cout<<"Prvi niz: ";
for (auto x: a) std::cout<< x <<" ";
std::cout<<std::endl<<"Drugi niz: ";
for (auto x:b) std::cout<< x<<" ";


	return 0;
}
