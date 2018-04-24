// Nazwa pliku wykonywalnego: Magia

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na koñcu tego
// pliku.

// !!! UWAGA !!!
// Przy wykonaniu tego zadania nie wolno korzystac z
// zadnych funkcji i obiektow zawartych w bibliotece standardowej
// oprocz cout, endl, printf, malloc, free.

// Prosze zwrocic uwage na dobre zarzadzanie pamiecia, zwlaszcza na
// zwolnienie pamieci na koniec programu.

// Komentarze w kodzie pokazuja jakie wyjscie powinna generowac dana
// linia.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod). 

// Makefile dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Magia. Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym w³asnych wczesniej
// przygotowanych plikow oprócz makefile)

// Kody zrodlowe musza znajdowac sie w katalogu do ktorego nikt oprocz
// wlasciciela nie ma praw dostepu.

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy wgrac
// do UPEL: upel.agh.edu.pl/wfiis/course/view.php?id=22

#include "Main.h"
#include "Main.h"

#include<iostream>

int main()
{
	Czary klasycznyCzarPoczatek, klasycznyCzarKoniec;
	UtworzCzar("Abra kadabra, hokus pokus", &klasycznyCzarPoczatek, &klasycznyCzarKoniec);
	std::cout << "Poziom klasycznego czaru: " << klasycznyCzarKoniec - klasycznyCzarPoczatek << "\n"; // Poziom klasycznego czaru: 25
	RzucCzar(klasycznyCzarPoczatek, klasycznyCzarKoniec); // Abra kadabra, hokus pokus

	std::cout << "\nRzucam kawalek klasycznego czaru\n";
	RzucCzar(klasycznyCzarPoczatek, klasycznyCzarPoczatek + 10); // Abra kadab

	Czary zlozonyCzarPoczatek, zlozonyCzarKoniec;
	UtworzCzar("Bidzia bidzia bim", &zlozonyCzarPoczatek, &zlozonyCzarKoniec);
	std::cout << "Poziom zlozonego czaru: " << zlozonyCzarKoniec - zlozonyCzarPoczatek << "\n"; // Poziom zlozonego czaru: 17
	RzucCzar(zlozonyCzarPoczatek, zlozonyCzarKoniec); // Bidzia bidzia bim

	KsiegaCzarow ksiega = 0;
	DodajCzar(&ksiega, klasycznyCzarPoczatek, klasycznyCzarKoniec);
	Czytaj(&ksiega);		// KSIEGA CZAROW \n Abra kadabra, hokus pokus

	DodajCzar(&ksiega, zlozonyCzarPoczatek, zlozonyCzarKoniec);
	Czytaj(&ksiega);		// KSIEGA CZAROW \n Abra kadabra, hokus pokus \n\n Bidzia bidzia bim \n\n

	SpalKsiege(ksiega);

	ZniszczCzar(klasycznyCzarPoczatek, klasycznyCzarKoniec);
	ZniszczCzar(zlozonyCzarPoczatek, zlozonyCzarKoniec); 
	

	return 0;
}
/* wynik dzialania programu:
Poziom klasycznego czaru: 25
Abra kadabra, hokus pokus

Rzucam kawalek klasycznego czaru
Abra kadab
Poziom zlozonego czaru: 17
Bidzia bidzia bim
KSIEGA CZAROW
Abra kadabra, hokus pokus

KSIEGA CZAROW
Abra kadabra, hokus pokus

Bidzia bidzia bim

*/
