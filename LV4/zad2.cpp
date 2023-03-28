//TP 2022/2023: LV 4, Zadatak 2
#include <iostream>
#include <cmath>
#include <string>
void IzvrniString(std::string &s){
int n=s.length();
for (int i=0; i<n/2; i++){
    std::swap(s[i],s[n-i-1]);
}
}
int main ()
{
std::string string;
std::cout<<	"Unesi string: ";
std::getline(std::cin, string);
IzvrniString(string);
std::cout<<"Izvrnuti string je: "<<string;
	return 0;
}
