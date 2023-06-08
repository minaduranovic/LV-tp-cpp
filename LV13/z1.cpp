#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <stdexcept>

class Lik {
public:
    virtual void IspisiSpecificnosti() const = 0;
    virtual double DajObim() const = 0;
    virtual double DajPovrsinu() const = 0;

    void Ispisi() const {
        IspisiSpecificnosti();
        std::cout << "Obim: " << DajObim() << std::endl;
        std::cout << "Povrsina: " << DajPovrsinu() << std::endl;
    }
};


class Krug : public Lik {
    double r;
public:
    Krug(double r) : r(r) {
        if(r <= 0) throw std::domain_error("Neispravni parametri");
    }
    void IspisiSpecificnosti() const override {
        std::cout << "Krug poluprecnika " << r << std::endl;
    }
    double DajObim() const override {
        return 2 * 4*atan(1)* r;
    }
    double DajPovrsinu() const override {
        return 4*atan(1) * r * r;
    }
};


class Pravougaonik : public Lik {
    double a, b;
public:
    Pravougaonik(double a, double b) : a(a), b(b) {
        if(a <= 0 || b <= 0) throw std::domain_error("Neispravni parametri");
    }
    void IspisiSpecificnosti() const override {
        std::cout << "Pravougaonik sa stranicama duzine " << a << " i " << b << std::endl;
    }
    double DajObim() const override {
        return 2 * (a + b);
    }
    double DajPovrsinu() const override {
        return a * b;
    }
};


class Trougao : public Lik {
    double a, b, c;
public:
    Trougao(double a, double b, double c) : a(a), b(b), c(c) {
        if(a <= 0 || b <= 0 || c <= 0 || a+b <= c || a+c <= b || b+c <= a) throw std::domain_error("Neispravni parametri");
    }
    void IspisiSpecificnosti() const override {
        std::cout << "Trougao sa stranicama duzine " << a << ", " << b << " i " << c << std::endl;
    }
    double DajObim() const override {
        return a + b + c;
    }
    double DajPovrsinu() const override {
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
};
int main() {
    std::vector<std::unique_ptr<Lik>> likovi;
    int brojLikova;

    std::cout << "Koliko zelite likova: ";
    std::cin >> brojLikova;
    std::cin.ignore();  // Ignorisi novi red nakon broja likova

    for (int i = 0; i < brojLikova; ++i) {
        char tip;
        bool ispravanUnos = false;

        while (!ispravanUnos) {
            std::cout << "Lik " << i + 1 << ": ";
            std::cin >> tip;

            try {
                if (tip == 'K') {
                    double r;
                    std::cin >> r;
                    likovi.push_back(std::make_unique<Krug>(r));
                    ispravanUnos = true;
                } else if (tip == 'P') {
                    double a, b;
                    std::cin >> a >> b;
                    likovi.push_back(std::make_unique<Pravougaonik>(a, b));
                    ispravanUnos = true;
                } else if (tip == 'T') {
                    double a, b, c;
                    std::cin >> a >> b >> c;
                    likovi.push_back(std::make_unique<Trougao>(a, b, c));
                    ispravanUnos = true;
                } else {
                    std::cin.clear(); // Resetuj stanje `cin` da se osigura da su sledeci unosi ispravni
                    std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
                }
                std::cin.ignore(1000, '\n'); // Ignorisi ostatak linije
            } catch (std::domain_error& e) {
                std::cin.clear(); // Resetuj stanje `cin` da se osigura da su sledeci unosi ispravni
                std::cin.ignore(1000, '\n'); // Ignorisi ostatak linije
                std::cout << "Pogresni podaci, ponovite unos!" << std::endl;
            }
        }
    }

    for (auto& lik : likovi) {
        lik->Ispisi();
        std::cout << std::endl;
    }

    return 0;
}