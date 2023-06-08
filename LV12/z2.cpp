//TP 2022/2023: LV 12, Zadatak 2
#include <iostream>
#include <cmath>
#include <set>
template<typename Tip>
std::set<Tip> operator +(const std::set<Tip> s1, const std::set<Tip> s2){
    std::set<Tip> unija;
    for(Tip x : s1) unija.insert(x);
    for(Tip x : s2) if(unija.find(x) == unija.end()) unija.insert(x);
    return unija;
}
template<typename Tip>
std::set<Tip> &operator +=(std::set<Tip> &s1, const std::set<Tip> s2){
    for(Tip x: s2) s1.insert(x);
    return s1;
}
template<typename Tip>
std::set<Tip> operator *(const std::set<Tip> s1, const std::set<Tip> s2){
        std::set<Tip> presjek;
    for(Tip x : s1) if(s2.find(x) != s2.end()) presjek.insert(x);
    return presjek;
}
template<typename Tip>
std::set<Tip> &operator *=(std::set<Tip> &s1, const std::set<Tip> s2){
        std::set<Tip> presjek;
    for(Tip x : s1) if(s2.find(x) != s2.end()) presjek.insert(x);
    s1 = presjek;
    return s1;
}

template<typename Tip>
std::ostream &operator<<(std::ostream &tok, const std::set<Tip> s){
    if(s.size() == 0) return tok << "{}";
    tok << "{" ;
    for(auto it = s.begin(); it != s.end(); it++){
        if( it == prev(s.end()))  return tok << *it <<"}";
        tok << *it << ",";  
 }
}
template<typename Tip1, typename Tip2>
auto operator %(const std::set<Tip1> &s1, const std::set<Tip2> &s2){
    std::set<std::pair<Tip1, Tip2>> dp; 
    for(auto x : s1){
        for(auto y : s2){
            dp.insert(std::make_pair(x, y));
        }
    }
    return dp;
} 
template<typename Tip1, typename Tip2>
std::ostream &operator <<(std::ostream &tok, const std::set<std::pair<Tip1, Tip2>> s){
    tok << "{";
    for(auto it = s.begin(); it!= s.end(); it++){
        if(it == prev(s.end())) return tok << "(" << it->first << "," << it->second << ")}";
        tok << "(" << it->first << "," << it->second << "),";
    }
}
int main ()
{
    std::set<int> s1{3, 5, 1, 2, 8}, s2{7, 2, 8, 4};
std::cout << s1 + s2 << std::endl; // Ispis "{1,2,3,4,5,7,8}"
std::cout << s1 * s2 << std::endl; // Ispis "{2,8}"
std::set<char> s3{'A', 'B'};
std::set<int> s4{1, 2, 3};
std::cout << s3 % s4 << std::endl; // Ispis "{(A,1),(A,2),(A,3),(B,1),(B,2),(B,3)}"*/


	return 0;
}