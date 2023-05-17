//TP 2022/2023: LV 7, Zadatak 7
#include <iostream>
#include <cmath>
#include <iterator>
#include<set>
template<typename tip>
std::set<tip> Unija(std::set<tip> skup1, std::set<tip> skup2){
    std::set<tip> unija=skup1;

for (auto &x:skup2) unija.insert(x);
return unija;
}

template<typename tip>
std::set<tip> Presjek(std::set<tip> skup1, std::set<tip> skup2){
    std::set<tip> presjek;

    for(auto x: skup1){
        for(auto &y: skup2){
            if(x==y){
                presjek.insert(x);
            }
        }
    }
    return presjek;

}
int main ()
{
    std::set<std::string> skup1={"prvi", "drugi", "treci"};
    std::set<std::string> skup2={"treci", "cetvrti", "peti"};

auto unija=Unija(skup1,skup2);
auto presjek=Presjek(skup1,skup2);
std::cout<<"Unija: ";
for(auto &x:unija) std::cout<<x<<" ";
std::cout<<"\nPresjek: ";
for(auto &x:presjek) std::cout<<x<<" ";

	return 0;
}
