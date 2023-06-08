// TP 2022/2023: LV 12, Zadatak 6
#include <cstring>
#include <iomanip>
#include <iostream>
#include <new>
#include <stdexcept>


template <typename TipEl> class Matrica {
  char ime_matrice;
  int br_redova, br_kolona;
  TipEl **elementi;

  static TipEl **AlocirajMemoriju(int br_redova, int br_kolona);
  static void DealocirajMemoriju(TipEl **elementi, int br_redova);
  void KopirajElemente(TipEl **elementi);

public:
  Matrica(int br_redova, int br_kolona, char ime = 0);
  Matrica(const Matrica &m);
  Matrica(Matrica &&m);
  ~Matrica() { DealocirajMemoriju(elementi, br_redova); }

  Matrica &operator=(const Matrica &m);
  Matrica &operator=(Matrica &&m);

  template<typename t>
  friend Matrica<t> operator+(const Matrica<t> &m1, const Matrica<t> &m2) ;
template<typename t>
  friend Matrica<t> operator-(const Matrica<t> &m1, const Matrica<t> &m2) ;

  template<typename t>
  friend Matrica<t> operator*(const Matrica<t> &m1, const Matrica<t> &m2) ;
 
 template<typename t>
  friend Matrica<t> operator*(int broj, const Matrica<t> &m) ;

 template<typename t>
  friend Matrica<t> operator*( const Matrica<t> &m, int broj) ;

template <typename t>
friend Matrica<t> &operator+=(Matrica<t> &m1, const  Matrica<t> &m2);

 template <typename t>
friend Matrica<t> &operator-=( Matrica<t> &m1,  const Matrica<t> &m2);

template <typename t>
friend Matrica<t> &operator*=(Matrica<t> &m1, const Matrica<t> &m2);

template <typename t>
friend Matrica<t> &operator*=(Matrica<t> &m1,int broj);

  TipEl *operator[](int indeks)const;

  TipEl &operator()(int i, int j)const;


  template <typename T>
  friend std::istream& operator>>(std::istream& is, Matrica<T>& m);

    template <typename Tip2>
 friend std::ostream &operator<<(std::ostream &os, const Matrica<Tip2> &m);

operator std::string() const;
};


template <typename TipEl>
TipEl **Matrica<TipEl>::AlocirajMemoriju(int br_redova, int br_kolona) {
  TipEl **elementi = new TipEl *[br_redova] {};
  try {
    for (int i = 0; i < br_redova; i++)
      elementi[i] = new TipEl[br_kolona];
  } catch (...) {
    DealocirajMemoriju(elementi, br_redova);
    throw;
  }
  return elementi;
}

template <typename TipEl>
void Matrica<TipEl>::DealocirajMemoriju(TipEl **elementi, int br_redova) {
  for (int i = 0; i < br_redova; i++)
    delete[] elementi[i];
  delete[] elementi;
}

template <typename TipEl>
void Matrica<TipEl>::KopirajElemente(TipEl **elementi) {
  for (int i = 0; i < br_redova; i++)
    for (int j = 0; j < br_kolona; j++)
      Matrica::elementi[i][j] = elementi[i][j];
}

template <typename TipEl>
Matrica<TipEl>::Matrica(int br_redova, int br_kolona, char ime) :
    br_redova(br_redova), br_kolona(br_kolona), ime_matrice(ime),
    elementi(AlocirajMemoriju(br_redova, br_kolona)){}

template <typename TipEl>
Matrica<TipEl>::Matrica(const Matrica<TipEl> &m) : 
    br_redova(m.br_redova),
    br_kolona(m.br_kolona),
    ime_matrice(m.ime_matrice),
    elementi(AlocirajMemoriju(m.br_redova, m.br_kolona)) {
  KopirajElemente(m.elementi);
}

template <typename TipEl>
Matrica<TipEl>::Matrica(Matrica<TipEl> &&m) : 
    br_redova(m.br_redova),
    br_kolona(m.br_kolona),
    elementi(m.elementi),
    ime_matrice(m.ime_matrice) {
  m.br_redova = 0;
  m.elementi = nullptr;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator=(const Matrica<TipEl> &m) {
  if (br_redova < m.br_redova || br_kolona < m.br_kolona) {
    TipEl **novi_prostor = AlocirajMemoriju(m.br_redova, m.br_kolona);
    DealocirajMemoriju(elementi, br_redova);
    elementi = novi_prostor;
  } else if (br_redova > m.br_redova) {
    for (int i = m.br_redova; i < br_redova; i++)
      delete elementi[i];
  }
  br_redova = m.br_redova;
  br_kolona = m.br_kolona;
  ime_matrice = m.ime_matrice;
  KopirajElemente(m.elementi);
  return *this;
}

template <typename TipEl>
Matrica<TipEl> &Matrica<TipEl>::operator=(Matrica<TipEl> &&m) {
  std::swap(br_redova, m.br_redova);
  std::swap(br_kolona, m.br_kolona);
  std::swap(ime_matrice, m.ime_matrice);
  std::swap(elementi, m.elementi);
  return *this;
}

template <typename TipEl>
Matrica<TipEl> operator+(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
  if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");

  Matrica<TipEl> rezultat(m1.br_redova, m1.br_kolona);
  for (int i = 0; i < m1.br_redova; i++)
    for (int j = 0; j < m1.br_kolona; j++)
      rezultat.elementi[i][j] = m1.elementi[i][j] + m2.elementi[i][j];

  return rezultat;
}

template <typename TipEl>
Matrica<TipEl> operator-(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2) {
  if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");

  Matrica<TipEl> rezultat(m1.br_redova, m1.br_kolona);
  for (int i = 0; i < m1.br_redova; i++)
    for (int j = 0; j < m1.br_kolona; j++)
      rezultat.elementi[i][j] = m1.elementi[i][j] - m2.elementi[i][j];

  return rezultat;
}

template <typename TipEl>
Matrica<TipEl> operator*(const Matrica<TipEl> &m1, const Matrica<TipEl> &m2)  {
  if (m1.br_kolona != m2.br_redova)
    throw std::domain_error("Matrice nisu saglasne za mnozenje");
  Matrica<TipEl> rezultat(m1.br_redova, m2.br_kolona);
  for (int i = 0; i < m1.br_redova; i++) {
    for (int j = 0; j < m2.br_kolona; j++) {
      TipEl suma = 0;
      for (int k = 0; k < m1.br_kolona; k++) {
        suma += m1.elementi[i][k] * m2.elementi[k][j];
      }
      rezultat.elementi[i][j] = suma;
    }
  }

  return rezultat;
}
 template<typename TipEl>
 Matrica<TipEl> operator*(int broj, const Matrica<TipEl> &m) {
  Matrica<TipEl> rezultat(m.br_redova, m.br_kolona);
  for (int i = 0; i < m.br_redova; i++)
    for (int j = 0; j < m.br_kolona; j++)
      rezultat.elementi[i][j] = m.elementi[i][j] * broj;
  return rezultat;
}
template<typename TipEl>
 Matrica<TipEl> operator*(const Matrica<TipEl> &m,int broj) {
  Matrica<TipEl> rezultat(m.br_redova, m.br_kolona);
  rezultat=broj*m;
  return rezultat;
}

template <typename TipEl>
Matrica<TipEl> &operator*=( Matrica<TipEl> &m1, const Matrica<TipEl> &m2)  {
  if (m1.br_kolona != m2.br_redova)
    throw std::domain_error("Matrice nisu saglasne za mnozenje");
m1=m1*m2;

  return m1;
}
template <typename t>
Matrica<t> &operator*=(Matrica<t> &m1,int broj){
    m1=m1*broj;
    return m1;
}

template <typename TipEl>
Matrica<TipEl> &operator+=(Matrica<TipEl> &m1,const Matrica<TipEl> &m2) {
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
  for (int i = 0; i < m1.br_redova; i++)
    for (int j = 0; j < m1.br_kolona; j++)
     m1.elementi[i][j] += m2.elementi[i][j];

  return m1;
}

template <typename TipEl>
Matrica<TipEl> &operator-=( Matrica<TipEl> &m1,const Matrica<TipEl> &m2) {
    if (m1.br_redova != m2.br_redova || m1.br_kolona != m2.br_kolona)
    throw std::domain_error("Matrice nemaju jednake dimenzije!");
 for (int i = 0; i < m1.br_redova; i++)
    for (int j = 0; j < m1.br_kolona; j++)
     m1.elementi[i][j] -= m2.elementi[i][j];

  return m1;
}
template <typename TipEl>
std::ostream &operator<<(std::ostream &os, const Matrica<TipEl> &m) {

    
  for (int i = 0; i < m.br_redova; i++) {
    for (int j = 0; j < m.br_kolona; j++) {
      os <<std::setw(4) << m.elementi[i][j];
    }
    os << std::endl;
  }
  return os;
}
template <typename TipEl>
std::istream& operator>>(std::istream& is, Matrica<TipEl>& m) {
  for (int i = 0; i < m.br_redova; i++) {
    for (int j = 0; j < m.br_kolona; j++) {
      TipEl element;
      std::cout<<m.ime_matrice<<"("<<i+1<<","<<j+1<<") = ";
      is >> element;
      m.elementi[i][j] = element;
    }
  }

  return is;
}

template <typename TipEl>
TipEl* Matrica<TipEl>::operator[](int indeks)const {
  return elementi[indeks];
}

template <typename TipEl>
TipEl& Matrica<TipEl>::operator()(int i, int j) const {
  if (i < 1 || i > br_redova || j < 1 || j > br_kolona)
    throw std::range_error("Neispravan indeks");
  return elementi[i - 1][j - 1];
}
template <typename TipEl>
Matrica<TipEl>::operator std::string() const {
    std::string rezultat = "{{";
    for (int i = 0; i < br_redova; ++i) {
        for (int j = 0; j < br_kolona; ++j) {
            rezultat += (std::to_string(int((elementi[i][j]))));
            if (j != br_kolona - 1) rezultat += ",";
        }
        rezultat += "}";
        if (i != br_redova - 1) rezultat += ",{";
    }
    rezultat += "}";
    return rezultat;
}

int main(){
 try {
Matrica<double> a(2, 2, 'a');
a[0][0] = 10; a[0][1] = 2; 
a[1][0] = 4; a[1][1] = 5; 
std::cout << std::string(a);
  }
  catch(std::bad_alloc) {
    std::cout << "Nema dovoljno memorije!\n";
  }
    catch(std::domain_error e) {
    std::cout << e.what();
  }
    catch(std::range_error e) {
    std::cout << e.what();
  }

  return 0;
}
