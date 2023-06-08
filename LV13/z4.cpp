//TP 2022/2023: LV 13, Zadatak 4
#include <iostream>
#include <cmath>
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



class Student {
    ApstraktniStudent* student;

public:
    Student() : student(nullptr) {}
    Student(const ApstraktniStudent &s) : student(s.DajKopiju()) {}
    
    Student(const Student &s) : student( s.student->DajKopiju() ) {}
    std::string DajIme(){ return student->DajIme();}
     std::string DajPrezime() const { return student->DajPrezime(); }
    int DajBrojIndeksa() const { return student->DajBrojIndeksa(); }
    int DajBrojPolozenih() const { return student->DajBrojPolozenih(); }
    double DajProsjek() const { return student->DajProsjek(); }
    void PonistiOcjene() {
        auto p=student->DajBrojPolozenih();
        auto q=student->DajProsjek();
        p=0;q=0;
    }
    Student& operator=(const Student &s) {
        if(this != &s) {
            delete student;
            student =  s.student->DajKopiju() ;
        }
        return *this;
    }

    ~Student() { delete student; }

    void RegistrirajIspit(int ocjena) { student->RegistrirajIspit(ocjena);
    }

    void IspisiPodatke() const {student->IspisiPodatke();
    }
};
int main ()
{
  StudentBachelor sb("Dusko", "Dugousko", 1234);
  StudentMaster sm("Paja", "Patak", 4312, 2015);
  Student s1(sb), s2(sm);
  s1.RegistrirajIspit(6); s1.RegistrirajIspit(9);
  s2.RegistrirajIspit(8);
  s1.IspisiPodatke();
  s2.IspisiPodatke();

	return 0;
}
