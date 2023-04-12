//TP 2022/2023: LV 6, Zadatak 3
#include <iostream>
#include <cmath>
#include <new>
#include <stdexcept>

int **KreirajTrougao(int n){
    if (n<=0) throw std::domain_error("Broj redova mora biti pozitivan");
    int** trougao=nullptr;

    try{
        trougao=new int*[n];
        for (int i=0; i<n; i++){
            try{
            trougao[i]= new int [2*i+1];
            }catch(std::bad_alloc){
                for (int j = 0; j < i; j++) {
                    delete[] trougao[j];
                }
                delete[] trougao;
                trougao = nullptr;
                throw std::bad_alloc();
            }
            for (int j=0; j<=i; j++){
                trougao[i][j]=i+1-j;
                trougao[i][2*i-j]=i+1-j;
            }
        }
    }catch(std::bad_alloc ){
        if (trougao){
            for (int i=0; i<n; i++){
                delete[] trougao[i];
            }
            delete[] trougao;
        }
      throw std::bad_alloc();
    }
    return trougao;
}
int main ()
{
int n;
    std::cout << "Koliko zelite redova: ";
    std::cin >> n;

 int** trougao = nullptr;

    try {
        trougao = KreirajTrougao(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2 * i + 1; ++j) {
                std::cout << trougao[i][j] << " ";
            }
            std::cout << std::endl;
        }

        for (int i = 0; i < n; ++i) {
            delete[] trougao[i];
        }
        delete[] trougao;

    }catch (const std::bad_alloc& e) {
        std::cout << "Izuzetak: Nedovoljno memorije!" << std::endl;
        return 1;
    } catch (const std::domain_error& e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;
        return 1;
    } 
	return 0;
}
