//TP 2022/2023: LV 12, Zadatak 1
#include <iomanip>
#include <iostream>
#include <stdexcept>

class Sat {
  int sati, minute, sekunde;

  void normal() {
    int ukupno = sati * 3600 + minute * 60 + sekunde;
    if (ukupno < 0)
      ukupno = 86400 - ((-ukupno) % 86400);
    else
      ukupno = ukupno % 86400;

    sati = (ukupno / 3600) % 24;
    minute = (ukupno / 60) % 60;
    sekunde = ukupno % 60;
  }

public:
  Sat() : sati(0), minute(0), sekunde(0) {}
  Sat(int sati, int minute, int sekunde) {
    this->sati = sati;
    this->minute = minute;
    this->sekunde = sekunde;
    normal();
  }

  static bool DaLiJeIspravno(int sati, int minute, int sekunde) {
    return (sati >= 0 && sati <= 23) && (minute >= 0 && minute <= 59) &&
           (sekunde >= 0 && sekunde <= 59);
  }

  void Postavi(int sati, int minute, int sekunde) {
    if (DaLiJeIspravno(sati, minute, sekunde) == false)
      throw std::domain_error("Neispravno vrijeme");
    this->sati = sati;
    this->minute = minute;
    this->sekunde = sekunde;
  }

 
  friend Sat& operator++(Sat &s) {
    s.sekunde++;
    s.normal();
    return s;
  }

  friend Sat operator++(Sat &s,int) {  
    Sat temp=s;
    ++s;
    return temp;
  }

 friend Sat& operator--(Sat &s) {  
   s.sekunde--;
   s.normal();
    return s;
  }

 friend Sat operator--(Sat &s,int) {  
   Sat temp=s;
   --s;
    return temp;
  }

 friend Sat& operator+=(Sat&s,int brSek) { 
   s.sekunde+=brSek;
   s.normal();
    return s;
  }

 
friend Sat& operator-=(Sat &s,int brSek) { 
return (s += -brSek);
}

friend Sat operator+(const Sat &s, int brSek)  { 
Sat temp=s;
temp.sekunde+=brSek;
temp.normal();
return temp;
}

friend Sat operator-(const Sat &s, int brSek)  { 
return s+-brSek;
}
/////////
friend int operator- (const Sat &s1, const Sat &s2){
  int ukupno1=s1.sati * 3600 + s1.minute * 60 +s1.sekunde;
  int ukupno2=s2.sati * 3600 + s2.minute * 60 +s2.sekunde;
   return ukupno1-ukupno2;
}

friend std::ostream& operator<<(std::ostream& os, const Sat& s) { 
os << std::setw(2) << std::setfill('0') << s.sati << ":"
<< std::setw(2) << std::setfill('0') << s.minute << ":"
<< std::setw(2) << std::setfill('0') << s.sekunde;
return os;
}




int DajSate() const { return sati; }
int DajMinute() const { return minute; }
int DajSekunde() const { return sekunde; }

};
int main(){
  Sat s1(11, 4, 39);
  std::cout << s1 << std::endl;
  Sat s2(25, 150, 1000);
  std::cout << s2 << std::endl;
//   std::cout << s1 - s2 << std::endl;
  std::cout << s1 + 100 << std::endl;
  std::cout << s1 << std::endl;        
  std::cout << s1 - 100 << std::endl;
  std::cout << s1 << std::endl;
  s2 = s1 += 100; 
  std::cout << s2 << std::endl;

    return 0;
}
