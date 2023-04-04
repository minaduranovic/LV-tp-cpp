//TP 2022/2023: LV 5, Zadatak 5
#include <iostream>
#include <cmath>
#include <iomanip>

double TrapeznoPravilo(double (*f)(double), double a, double b, int n){
    double h=(b-a)/n;
    double sum=(f(a)+f(b))/2.0;
    for (int i=1; i<n; i++){
        double x=a+i*h;
        sum+=f(x);
    }
    return sum*h;
}
int main ()
{
int n;
std::cout<<"Unesite broj podintervala: ";
std::cin>>n;
std::cout<<"Za taj broj podintervala priblizne vrijednosti integrala iznose: ";
std::cout<<std::endl<<"- Za funkciju sin x na intervalu (0,pi): "<<std::fixed<<std::setprecision(5)<<TrapeznoPravilo(sin, 0, 4*atan(1), n);
std::cout<<std::endl<<"- Za funkciju x^3 na intervalu (0,10): "<<std::fixed<<std::setprecision(2)<<TrapeznoPravilo([](double x){return x*x*x;}, 0, 10, n);
std::cout<<std::endl<<"- Za funkciju 1/x na intervalu (1,2): "<<std::fixed<<std::setprecision(5)<<TrapeznoPravilo([](double x){return 1./x;}, 1, 2, n);

	return 0;
}
