#include <iostream>
#include <new>
#include <stdexcept>

int **KreirajTrougao(int n) {
    if (n <= 0) throw std::domain_error("Broj redova mora biti pozitivan");
    int **trougao = nullptr;

    try {
        trougao = new int *[n];
        trougao[0] = new int[n *n ]; 

        int m = 0;
        for (int i = 0; i < n; i++) {
            trougao[i] = trougao[0]+ m;
            m += 2 * i + 1;

            for (int j = 0; j <= i; j++) {
                trougao[i][j] = i + 1 - j;
            }
            for (int j = i + 1; j < 2 * i + 1; j++) {
                trougao[i][j] = j - i+1;
            }
        }
    } catch (std::bad_alloc &) {
        delete[] trougao;
        throw;
    }

    return trougao;
}


int main() {
    int n;
    std::cout << "Koliko zelite redova: ";
    std::cin >> n;

    int **trougao = nullptr;

    try {
        trougao = KreirajTrougao(n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 2 * i + 1;j++) {
                std::cout << trougao[i][j] << " ";
            }
            std::cout << std::endl;
        }

        delete[] trougao[0];
        delete[] trougao;

    } catch (const std::domain_error &e) {
        std::cout << "Izuzetak: " << e.what() << std::endl;
        return 1;
    } catch (const std::bad_alloc &e) {
        std::cout << "Izuzetak: Nedovoljno memorije!" << std::endl;
        return 1;
    }
    return 0;
}
