// TP 2022/2023: LV 8, Zadatak 4
#include <cmath>
#include <iostream>
#include <map>


std::string ZamijeniPremaRjecniku(std::string s,
                                  std::map<std::string, std::string> mapa) {
  std::string nova;
  std::string trenutna;

  for (char c : s) {
    if (c == ' ') {
      if (trenutna.size() != 0) {
        if (trenutna.size() > 0) {
          nova += ' ';
        }
        if (mapa.count(trenutna) > 0) {
          nova += mapa[trenutna];
        } else {
          nova += trenutna;
        }
        trenutna = "";
      }

    } else {
      trenutna += c;
    }
  }
  if (trenutna.size() != 0) {
    if (nova.size() > 0) {
      nova += ' ';
    }
    if (mapa.count(trenutna) > 0) {
      nova += mapa[trenutna];
    } else {
      nova += trenutna;
    }
  }

  return nova;
}
int main() {
  std::map<std::string, std::string> moj_rjecnik{{"jabuka", "apple"},
                                                 {"da", "yes"}};

  std::cout << ZamijeniPremaRjecniku("kako da ne", moj_rjecnik) << std::endl;

  return 0;
}
