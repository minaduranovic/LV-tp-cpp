//TP 2022/2023: LV 4, Zadatak 3
#include <iostream>
#include <cmath>
#include<vector>
#include<string>
#include<cctype>
std::string malaSlova(std::string s1){
    for(auto &s : s1) s=std::tolower(s);
    return s1;
} 
void IzdvojiKrajnjeRijeci(const std::vector<std::string> &rijeci, std::string &prva, std::string &zadnja){
    if(rijeci.size()==0){
        prva ="";
        zadnja = "";
        return;
    }
    prva = rijeci[0];
    zadnja = rijeci[0];

    for(const std::string &rijec : rijeci){
        if(malaSlova(rijec)<malaSlova(prva)) prva = rijec;
        if(malaSlova(rijec)>malaSlova(zadnja)) zadnja = rijec;
    }
        /*if(std::tolower(rijeci.at(i).at(j))<std::tolower(prva.at(0))) {
            if{}
            
        }
        
        if(std::tolower(rijeci.at(i).at(j))>std::tolower(zadnja.at(0))) zadnja = rijeci[i];
    }*/
}

void ZadrziDuplikate(std::vector<std::string> &rijeci){
    std::vector<std::string> duple_rijeci;
    for(int i=0; i<rijeci.size(); i++){
        for(int j=i+1; j<rijeci.size(); j++){
            if(rijeci[i]==rijeci[j]){
            bool vecDodala = false; 
            for(int k=0; k<duple_rijeci.size(); k++){
                if(rijeci[i]==duple_rijeci[k]) {
                    vecDodala = true;
                    break;
                    }
            }if(!(vecDodala)) duple_rijeci.push_back(rijeci[i]);
            }
        }
    }
    rijeci=duple_rijeci;
}
int main ()
{
    int n;
    std::string rijec, a, b;
    std::cout<<"Koliko zelite unijeti rijeci: ";
    std::cin>>n;
    std::vector<std::string> rijeci;
    std::cout<<"Unesite rijeci: ";
    for(int i=0; i<n; i++){
        std::cin>>rijec;
        rijeci.push_back(rijec);
    }
    IzdvojiKrajnjeRijeci(rijeci, a, b);
    ZadrziDuplikate(rijeci);
    std::cout<<"Prva rijec po abecednom poretku je: "<<a<<std::endl;
    std::cout<<"Posljednja rijec po abecednom poretku je: "<<b<<std::endl;
    std::cout<<"Rijeci koje se ponavljaju su: ";
    for(std::string s : rijeci){
        std::cout<<s<<" ";
    }
	return 0;
}
