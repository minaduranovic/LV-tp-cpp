//TP 2022/2023: LV 11, Zadatak 1
#include <iostream>
#include <cmath>

class NeobicnaKlasa{
public:
explicit NeobicnaKlasa(int  br){ std::cout << "Direktna inicijalizacija" <<std::endl;}
NeobicnaKlasa( long int br){ std::cout << "Kopirajuca inicijalizacija"<<std::endl;}
};
int main ()
{
NeobicnaKlasa k1(5);
NeobicnaKlasa k2=5;


	return 0;
}

