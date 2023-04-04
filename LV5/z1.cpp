//TP 2022/2023: LV 5, Zadatak 1
#include <cstdio>
#include <iostream>
#include <cmath>

int main ()
{
char recenica[1000];
std::cout<<"Unesite recenicu: ";
// std::cin.getline(recenica, sizeof(recenica));
char *p=recenica;
char*q=recenica;
// char prva[50];


char znak=getchar();
while (znak!='\n' ){
*p=znak;
p++;
znak=getchar();
}
*p='\0';

while(*q!='\0' && *q==' '){
    q++;
}
while (*q!='\0' && *q!=' '){
    q++;
}
while (*q!='\0' && *q==' '){
    q++;
}
std::cout<<"Recenica bez prve rijeci glasi: ";
if (*q!='\0') {
    std::cout<<q<<std::endl;
}
	return 0;
}
