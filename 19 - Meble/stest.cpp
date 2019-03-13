/* Celem zadania jest napisanie prostej klasy Mebel.
   Do klasy dodane musza byc odpowiednie operatory pozwalajace na zapis atrybutow 
   do pliku tekstowwego. 
   Taki plik tekstowy powinno sie tez dac wczytac pozniej do obiektu klasy.
   A nawet powinno sie dac wczytac wiel obiektow kl. Mbel do wektora.
   
   Mozna kozystac z dokumentacji na stronie:
   http://www.cplusplus.com  - lub podobnej. 
   UWAGA: Zagladanie na inne strony skutkuje 0pkt. 

   Kompilowac do pliku: stest   
 */

#include <fstream>
#include <iostream>

#include "Mebel.h"

int main() {

  Mebel m1("stol", 90,90,180, "Stol");
  Mebel m2("stol", 90,90,180, "Stol z fornirowanym blatem");
  Mebel m3("Szafa", 200,90,16, "Ubraniowka");

  std::cout << m2 << std::endl;

  std::cout << " -- do pliku\n";
  std::ofstream f("meble.txt");
  f << m1;
  f << m2;
  f << m3;
  f.close();

  std::cout << " -- z pliku\n";
  
  std::vector<Mebel> v;
  std::ifstream i("meble.txt");
  i >> v;
  i.close();
  std::cout << v.size() << std::endl;
  std::cout << v[0]  << std::endl;
  std::cout << v[1]  << std::endl;
  std::cout << v[2]  << std::endl;
   
}
/*
stol 90 90 180 "Stol z fornirowanym blatem" 
 -- do pliku
 -- z pliku
3
stol 90 90 180 "Stol" 
stol 90 90 180 "Stol z fornirowanym blatem" 
Szafa 200 90 16 "Ubraniowka" 

 */
