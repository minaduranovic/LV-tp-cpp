//TP 2022/2023: LV 4, Zadatak 5
#include <iostream>
#include <cmath>
#include <vector>
template<typename T>
std::vector<T>Presjek(const std::vector<T>&v1, const std::vector<T>&v2){
    std::vector<T> presjek;
    for(const auto &el1 : v1){
        bool postoji = false;
        for(const auto &el2:v2){
            if(el1==el2) postoji = true;
        }
        if(postoji){
             postoji=false;
            for(const auto &el : presjek){
                if(el1==el){
                    postoji = true;
                     break;}
            }
            if(!(postoji)) presjek.push_back(el1);
        }
    }
    return presjek;
}

int main ()
{
    int n,x;
    double broj1, broj2;
    std::cout<<"Test za realne brojeve..."<<std::endl;
    std::vector<double> v1, v2;
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    std::cin>> n;
    std::cout<<"Unesite elemente prvog vektora: "<<std::endl;
   for(int i=0; i<n; i++){
       std::cin>>broj1;
       v1.push_back(broj1);
   }
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>> x;
    std::cout<<"Unesite elemente drugog vektora: "<<std::endl;
   for(int i=0; i<x; i++){
       std::cin>>broj2;
       v2.push_back(broj2);
   }
   std::vector<double> rez1 = Presjek(v1, v2);
   std::cout<<"Zajednicki elementi su: ";
   for(auto x : rez1){
       std::cout<<x<<" ";
   }
   //STRINGOVI
   std::cout<<"Test za stringove..."<<std::endl;
std::string str1, str2;
std::vector<std::string> s1, s2;
    std::cout<<"Unesite broj elemenata prvog vektora: ";
    std::cin>> n;
    std::cin.ignore(10000, '\n');
    std::cout<<"Unesite elemente prvog vektora (ENTER nakon svakog unosa): "<<std::endl;
   for(int i=0; i<n; i++){
       std::getline(std::cin, str1);
       s1.push_back(str1);
   }
    std::cout<<"Unesite broj elemenata drugog vektora: ";
    std::cin>> x;
    std::cin.ignore(10000, '\n');
    std::cout<<"Unesite elemente drugog vektora (ENTER nakon svakog unosa): "<<std::endl;
   for(int i=0; i<x; i++){
      std::getline(std::cin, str2);
       s2.push_back(str2);
   }
   std::vector<std::string> rez2 = Presjek(s1, s2);
   std::cout<<"Zajednicki elementi su: "<<std::endl;
   for(auto x : rez2){
       std::cout<<x << std::endl;
   }
	return 0;
}
