//TP 2022/2023: LV 5, Zadatak 7
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <type_traits>
#include <vector>

template<typename itertip>
auto SumaBloka(itertip poc, itertip kraj)->typename std::remove_reference<decltype(*poc +*poc)>::type
{
    if (poc==kraj) throw std::range_error("Blok je prazan");
    auto suma=*poc;
    while(++poc!=kraj){
        suma+=*poc;
    }
    return suma;
}
int main ()
{
std::vector<int> a={1,2,3,4,5,6,7,8,9};
auto b=SumaBloka(a.begin(), a.end());
std::cout<<"Suma bloka a= "<<b;

	return 0;
}
