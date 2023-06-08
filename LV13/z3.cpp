//TP 2022/2023: LV 13, Zadatak 3
#include <iostream>
#include <cmath>
#include <vector>
#include<algorithm>

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
//fakultet
class Fakultet {
    std::vector<ApstraktniStudent*> studenti;

    void Kopiraj(const Fakultet &f);
    void Premjesti(Fakultet &f);
    void Obrisi();
public:
    Fakultet() = default;
    Fakultet(const Fakultet &f);
    Fakultet(Fakultet &&f);
    ~Fakultet();
    Fakultet& operator=(const Fakultet &f);
    Fakultet& operator=(Fakultet &&f);

    void UpisiStudenta( const std::string &ime, const std::string &prezime,int br_ind);
    void UpisiStudenta( const std::string &ime, const std::string &prezime,int br_ind, int god);
    void ObrisiStudenta(int br_ind);

    ApstraktniStudent& operator[](int br_ind);
    const ApstraktniStudent& operator[](int brojIndeksa) const;

    void IspisiSveStudente() const;
};
  Fakultet::~Fakultet(){
     for(auto p: studenti)
        delete p;
  }
Fakultet::Fakultet(const Fakultet &f) {
  for(auto p : f.studenti)
        studenti.push_back(p->DajKopiju());
}

Fakultet::Fakultet(Fakultet &&f) {
   std::swap(studenti, f.studenti);
}


Fakultet& Fakultet::operator=(const Fakultet &f) {
    if (&f != this) {
        for(auto student : studenti)
            delete student;    
        studenti = std::vector<ApstraktniStudent*>();
            for(auto student : f.studenti)
                studenti.push_back(student->DajKopiju());
       
    }
    return *this;
}

Fakultet& Fakultet::operator=(Fakultet &&f) {
    if (&f != this) {
        for(auto student : studenti)
            delete student;
        studenti = std::move(f.studenti);
        f.studenti = std::vector<ApstraktniStudent*>();
    }
    return *this;
}



void Fakultet::UpisiStudenta( const std::string &ime, const std::string &prezime,int br_ind) {
    for(auto& student : studenti)
        if(student->DajBrojIndeksa() == br_ind)
            throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
    studenti.push_back(new StudentBachelor(ime, prezime, br_ind));
}

void Fakultet::UpisiStudenta(const std::string &ime, const std::string &prezime, int br_ind,int god) {
    for(auto& student : studenti)
        if(student->DajBrojIndeksa() == br_ind)
            throw std::logic_error("Student sa zadanim brojem indeksa vec postoji");
    studenti.push_back(new StudentMaster(ime, prezime, br_ind, god));
}

void Fakultet::ObrisiStudenta(int brojIndeksa) {
    bool flag= false;
    std::vector<ApstraktniStudent*> novi;
    for(auto it = studenti.begin(); it != studenti.end(); it++) {
        if((*it)->DajBrojIndeksa() == brojIndeksa) {
            delete *it;
            flag = true;
        } else {
            novi.push_back(*it);
        }
    }
    if (!flag) {
        throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
    }
    studenti = novi;
}

ApstraktniStudent& Fakultet::operator[](int brojIndeksa) {
    for(auto& student : studenti)
        if(student->DajBrojIndeksa() == brojIndeksa)
            return *student;
    throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
}

const ApstraktniStudent& Fakultet::operator[](int brojIndeksa) const {
    for(auto& student : studenti)
        if(student->DajBrojIndeksa() == brojIndeksa)
            return *student;
    throw std::logic_error("Student sa zadanim brojem indeksa ne postoji");
}

void Fakultet::IspisiSveStudente() const {
    std::vector<int> indeksi;
    for (int i = 0; i < studenti.size(); ++i)
        indeksi.push_back(i);

    std::sort(indeksi.begin(), indeksi.end(), [this](int a, int b) {
        if(studenti[a]->DajProsjek() !=studenti[b]->DajProsjek())
            return studenti[a]->DajProsjek() > studenti[b]->DajProsjek();
        else
            return studenti[a]->DajBrojIndeksa() < studenti[b]->DajBrojIndeksa();
    });
    for(auto i : indeksi)
        studenti[i]->IspisiPodatke();
}

int main ()
{
    Fakultet f1;
  f1.UpisiStudenta("Meho", "Mehic", 3412);
  f1.UpisiStudenta("Ibro", "Ibric", 3124, 2015);
  f1.UpisiStudenta("Pero", "Peric", 1243);
 
  const Fakultet f4(f1);    
  f4.IspisiSveStudente();
  f4[3124].IspisiPodatke();

	return 0;
}
