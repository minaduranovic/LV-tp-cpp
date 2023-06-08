//TP 2022/2023: LV 12, Zadatak 5
#include <iostream>
#include <cmath>
class Kompleksni {
 double re, im;
public:
 Kompleksni(double re = 0, double im = 0) : re(re), im(im) {}
 friend Kompleksni operator +(const Kompleksni &a) { return a; }
 friend Kompleksni operator -(const Kompleksni &a) { return {-a.re, -a.im}; }
 friend Kompleksni operator +(const Kompleksni &a, const Kompleksni &b) {
 return {a.re + b.re, a.im + b.im};
 }
   friend double real(const Kompleksni &a) { return a.re; }
 friend double imag(const Kompleksni &a) { return a.im; }

friend std::ostream &operator <<(std::ostream &tok, const Kompleksni &a) {
    if(fabs(a.im) < 1e-10) return tok << a.re;
    if(fabs(a.re) < 1e-10){           //razlicito od nule
        if(fabs(a.im-1) < 1e-10*fabs(a.im+1)){
                         return tok << "i"; //za y = 1        
            } 
        if(fabs(a.im+1) < 1e-10*fabs(a.im-1)) {
                 return tok << "-i"; // za y = -1        
        }
        if(a.im < 0){ return tok << a.im << "i";}
        else{
          return tok <<  a.im << "i";       
         }
    } else{
        tok << a.re;
        if(fabs(a.im-1) < 1e-10*fabs(a.im+1)){
                         return tok << "+i"; //za y = 1        
            } 
        if(fabs(a.im+1) < 1e-10*fabs(a.im-1)) {
                 return tok << "-i"; // za y = -1        
        }
        if(a.im < 0){ return tok << a.im << "i";}
        else{
          return tok << "+" <<a.im << "i";       
         }
    }         

 } };

int main ()
{
    std::cout << "Koliko zelite elemenata: ";
    int n; std::cin >> n;
    std::cout << "Unesite elemente: ";
    std::vector<double> v; double x;
    for(int i = 0; i < n; i++){  
        std::cin >> x;
        v.push_back(x);
    }
    std::cout << "Transformirani elementi: ";
    //std::transform(v.begin(), v.end(), v.begin(), std::bind1st(std::divides<double>(), 1));
    std::transform(v.begin(), v.end(), v.begin(), std::bind(std::divides<double>(), 1, std::placeholders::_1));
    for(auto x: v) std::cout << x << " "; 


	return 0;
}