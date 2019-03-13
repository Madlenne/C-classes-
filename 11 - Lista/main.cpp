/*
  Celem zadania jest napisanie polimorficznej kopiowalnej polaczonej listy.
  Zadanie posiada kilka haczykow. W szczegolnosci konstruktor kopiujacy. 

  UWAGA: Zadanie ma kontynuacje (w domu). 
         Prosze sie upewnic ze sie wie jak to zrobic na kolejne zajecia.
 */
#include <iostream>
#include "List.h"
//#include "Data.h"


int main() {
    List a;

    a.insert(IntData(10), List::Begin); // wkladamy na poczatek
    a.insert(IntData(11), List::End); // na koniec
    a.insert(StringData("Hello"),  List::Begin); // znow na poczatek
    a.insert(StringData("Kasia"), List::End);
    a.insert(IntData(7)).insert(FloatData(0.3)); // po wyniki mozna poznac gdzie dodane sa elementy

    a.print();

    List b = a;
    b.insert(IntData(99));
    std::cout << "Lista a" << std::endl;
    a.print();
    std::cout << "Lista b" << std::endl;
    b.print();
    // tu uruchamiaja sie destruktory

    // dla tych co sie nudza na zajeciach, (lub zad domowe)
   /*  bool found = a.find( IntData(7) );
     std::cout << " found " << found << std::endl;
     found = a.find( StringData("7") );
     std::cout << " found " << found << std::endl;

    IntData *test;
    Data* test2 = test;
    IntData *wynik;
*/
}

