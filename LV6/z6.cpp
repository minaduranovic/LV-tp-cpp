//TP 2022/2023: LV 6, Zadatak 2
#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>
#include <iterator>

template <typename it>
auto KreirajIzvrnutiNiz(it pocetak, it kraj) {
    using tip = typename std::remove_reference<decltype(*pocetak)>::type;
    int vel = 0;

    for (it i = pocetak; i != kraj; i++) {
        vel++;
    }

    tip* niz = nullptr;

    try {
        niz = new tip[vel];
    } catch ( std::bad_alloc&) {
        throw;
    }

    tip* trenutni = niz;
    for (it iter = kraj; iter != pocetak;) {
        vel--;
        it temp = pocetak;
        for (int i = 0; i < vel; i++) {
            temp++;
        }
        *trenutni = *temp;
        trenutni++;
        iter = temp;
    }

    return niz;
}

int main() {
    std::vector<double> vektor;
   int n;

    std::cout << "Koliko zelite elemenata: ";
    std::cin >>n;

    try {
        vektor.resize(n);

        std::cout << "Unesite elemente: ";
        for (int i = 0; i < n; ++i) {
            std::cin >> vektor[i];
        }

        double* izvrnuti = KreirajIzvrnutiNiz(vektor.begin(), vektor.end());

        std::cout << "Kreirani niz: ";
        double* kraj = izvrnuti + n;
        for (double* trenutni = izvrnuti; trenutni != kraj; trenutni++) {
            std::cout << *trenutni << " ";
        }
        std::cout << std::endl;

        delete[] izvrnuti;
    } catch (const std::bad_alloc&) {
        std::cout << "Nedovoljno memorije!" << std::endl;
    }

    return 0;
}
