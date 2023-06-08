//TP 2022/2023: LV 12, Zadatak 2
#include <iostream>
#include <cmath>
#include<array>

enum Dani {Ponedjeljak, Utorak, Srijeda, Cetvrtak, Petak, Subota, Nedjelja};
std::ostream &operator <<(std::ostream &tok, Dani d){
    std::array<std::string, 7> dani = {"Ponedjeljak", "Utorak", "Srijeda", "Cetvrtak", "Petak", "Subota", "Nedjelja"};
    return tok << dani.at(int(d)%7);
}
Dani &operator ++(Dani &d, int){
    return d = Dani((int(d)+1)%7);
}
int main ()
{ 
    for(Dani d = Ponedjeljak; d <= Petak; d++) std::cout << d << std::endl;
    //for(Dani d = Ponedjeljak; d <= Nedjelja; d++) std:: cout << d << std::endl; // besk petlja
    for(Dani d = Ponedjeljak; d < Nedjelja; d++) { 
        if(d == Subota){
            std::cout << d << std::endl;
            std::cout << Dani(d+1); break;
        }
        std:: cout << d << std::endl;
    }
	return 0;
}