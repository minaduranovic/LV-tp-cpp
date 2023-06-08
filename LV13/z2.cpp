//TP 2022/2023: LV 13, Zadatak 2
#include <iostream>
#include<cmath>
#include <stdexcept>
#include <string>

class ApstraktniStudent {
    std::string ime, prezime;
    int br_ind, br_polozenih;
    double prosjek;

public:
    ApstraktniStudent(const std::string &ime, const std::string &prezime, int brojIndeksa) :
        ime(ime), prezime(prezime), br_ind(brojIndeksa), br_polozenih(0), prosjek(5) { }

    std::string DajIme() const { return ime; }
    std::string DajPrezime() const { return prezime; }
    int DajBrojIndeksa() const { return br_ind; }
    int DajBrojPolozenih() const { return br_polozenih; }
    double DajProsjek() const { return prosjek; }

    void RegistrirajIspit(int ocjena) {
        if(ocjena < 5 || ocjena > 10) throw std::domain_error("Neispravna ocjena");
        if(ocjena == 5) return;
        prosjek = ((prosjek * br_polozenih) + ocjena) / (br_polozenih+ 1);
        br_polozenih++;
    }

    void PonistiOcjene() {
        br_polozenih = 0;
        prosjek = 5;
    }

    virtual void IspisiPodatke() const = 0;
    virtual ApstraktniStudent* DajKopiju() const = 0;
    virtual ~ApstraktniStudent(){}
};

class StudentBachelor : public ApstraktniStudent {
public:
    StudentBachelor(const std::string &ime, const std::string &prezime, int br_ind) :
        ApstraktniStudent(ime, prezime, br_ind) { }

    void IspisiPodatke() const override {
        std::cout << "Student bachelor studija " << DajIme() << " " << DajPrezime()
                  << ", sa brojem indeksa " << DajBrojIndeksa()<<",\n"
                  << "ima prosjek " << DajProsjek() << ".\n";
    }

    StudentBachelor* DajKopiju() const override {
        return new StudentBachelor(*this);
    }
     ~StudentBachelor() override {}
};

class StudentMaster : public ApstraktniStudent {
    int god;

public:
    StudentMaster(const std::string &ime, const std::string &prezime, int brojIndeksa, int godina) :
        ApstraktniStudent(ime, prezime, brojIndeksa), god(godina) { }

    void IspisiPodatke() const override {
        std::cout << "Student master studija " << DajIme() << " " << DajPrezime()
                  << ", sa brojem indeksa " << DajBrojIndeksa()<<",\n"
                  << "zavrsio bachelor studij godine " << god
                  << ",ima prosjek " << DajProsjek() << ".\n";
    }

    StudentMaster* DajKopiju() const override {
        return new StudentMaster(*this);
    }
     ~StudentMaster() override {}
};


int main() {

        StudentBachelor sb("Miki", "Maus", 1234);
        sb.RegistrirajIspit(9);
        sb.RegistrirajIspit(8);
        sb.IspisiPodatke();
        StudentMaster sm("Mini", "Maus", 2345, 2022);
        sm.RegistrirajIspit(9);
        sm.RegistrirajIspit(10);
        sm.IspisiPodatke();
        ApstraktniStudent *p = sb.DajKopiju();
        p->IspisiPodatke();
        delete p;
        p = sm.DajKopiju();
        p->IspisiPodatke();
        delete p;
   

    return 0;
}

