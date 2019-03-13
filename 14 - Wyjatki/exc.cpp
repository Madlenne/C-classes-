// Obsluga wyjatkow
//
// Nalezy napisac klase wyjatku tak by ponizszy kod zadzialal poprawnie. 
//
// Dodatkowo nalezy napisac uchwyt obslugujacy wyjatki i wypisujacy informacje o wyjatku i jego przyczynach. 
// 
// Kompilowac z opcja -Wall -g do pliku wyk. o nazwie "exc".
// Prosze nie zmieniac nazwy tego pliku (ma byc exc.C)
// ani nie kopiowac do innego uwuwajac komentarze (zmienia sie wtedy numery linii w makrze __LINE__).

// UWAGA: Prosze zauwazyc ze wyrzucane sa wkazniki. To powinno pozwolic na "przechowanie" jednego wyjatku w drugim.
// 

#include <iostream>
#include "myerrors.h"
#include "myerrors.h"
using namespace std;


struct m {
  static void krok1() {
    // ... jakis tam kod powiedzmy
    throw new std::runtime_error("Bardzo powazny problem w 1");
  }

  static void krok2() {
    try {
      std::cout << "Krok 2" << std::endl;
      m::krok1();
    } catch (const std::runtime_error* err) {
      throw new myerrors::calc_error(err, "wyjatek z step2", __FILE__, __LINE__);
    }  
  }
    
  static void krok3() {
    try {
      std::cout << "Krok 3" << std::endl;
      krok2();
    } catch (const std::runtime_error* err) {
      throw new myerrors::calc_error(err, "wyjatek z step3", __FILE__, __LINE__);
    }  
  }
  
  static void moje_obliczenia(int arg) {
    try {
      std::cout << "Krok 4" << std::endl;
      krok3();
    } catch (const std::runtime_error* err) {
      throw new myerrors::calc_error(err, "moje_obliczenia", __FILE__, __LINE__);
    } 
  }
};




int main(int argc, char** argv) {
  try {
    m::moje_obliczenia(1); // wyrzuca wyjatek typu myerrors::calc_error
    throw new std::runtime_error("koniec"); // tu widac co rzucamy
  } catch (...) {
    myerrors::handler();
  }
}
/* wynik dzialania
Krok 4
Krok 3
Krok 2
Wyjatek w: moje_obliczenia [w pliku: exc.cpp w lini: 47] 
z powodu : wyjatek z step3 [w pliku: exc.cpp w lini: 38] 
z powodu : wyjatek z step2 [w pliku: exc.cpp w lini: 29] 
z powodu : Bardzo powazny problem w 1
*/
