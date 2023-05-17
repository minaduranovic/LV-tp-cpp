//TP 2022/2023: LV 7, Zadatak 3
#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::cout << "Koliko zelite recenica: ";
    int n;
    std::cin >> n;
    std::cin.ignore();

    std::string *niz = nullptr;
    std::cout << "Unesite recenice: ";
    try {
        niz = new std::string[n];

        for (int i = 0; i < n; i++) {
            std::getline(std::cin, niz[i]);
        }

        std::sort(niz, niz + n);

        std::cout << std::endl
                  << "Sortirane recenice: ";
        for (int i = 0; i < n; i++) {
            std::cout << niz[i];
            std::cout << std::endl;
        }
    } catch (...) {
        delete[] niz;
        std::cout << "\nProblemi s memorijom!";
        return 1;
    }

    delete[] niz;
    return 0;
}
