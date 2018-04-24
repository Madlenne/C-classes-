#include "gierka.h"

void setName(std::string &character_name)
{
	std::cout << "Podaj imie swojego bohatera: \n";
	std::cin >> character_name;
}

void setPoints(int &character_physical_defence, int &character_physical_attack, int &character_magic_defence, int &character_magic_attack, int &character_life, int max_points)
{
	using std::cout;
	using std::endl;
	using std::cin;
	cout << "Rozdziel 20 punktow na nastepujace atrybuty" << endl;
	cout << "(UWAGA: punkty moga byc tylko nieujemnymi liczbami calkowitymi, wszelkie czesci ulamkowe zostana obciete," << endl;
	cout << "a z ujemnych wartosci zostanie wyciagnieta wartosc bezwgledna!) : " << endl << endl;
	cout << "- obrona fizyczna" << endl;
	cout << "- atak fizyczny" << endl;
	cout << "- obrona magiczna" << endl;
	cout << "- atak magiczny" << endl;
	cout << "- punkty zycia (kazdy punkt atrybutu liczby sie za 2 zycia)" << endl << endl;
	cout << "Ile punktow przypisac do fizycznej obrony?   ";
	cin >> character_physical_defence;
	if (character_physical_defence < 0)
		character_physical_defence = abs(character_physical_defence);
	cin.clear();
	while (cin.get() != '\n');
	cout << "Ile punktow przypisac do fizycznego ataku?   ";
	cin >> character_physical_attack;
	if (character_physical_attack < 0)
		character_physical_attack = abs(character_physical_attack);
	cin.clear();
	while (cin.get() != '\n');
	cout << "Ile punktow przypisac do magicznej obrony?   ";
	cin >> character_magic_defence;
	if (character_magic_defence < 0)
		character_magic_defence = abs(character_magic_defence);
	cin.clear();
	while (cin.get() != '\n');
	cout << "Ile punktow przypisac do magicznego ataku?   ";
	cin >> character_magic_attack;
	if (character_magic_attack < 0)
		character_magic_attack = abs(character_magic_attack);
	cin.clear();
	while (cin.get() != '\n');
	int amount_of_points = character_physical_defence + character_physical_attack + character_magic_defence + character_magic_attack;
	int rest_of_points = max_points - amount_of_points;
	character_life = 2 * rest_of_points;
	cout << endl;
	cout << "Na zycie pozostalo: " << rest_of_points;
	cout << " co daje " << character_life << " punktow zycia" << endl;
	if (amount_of_points >= 20)
	{
		cout << "Zabraklo punktow na zycie, urodziles sie martwy\nKONIEC" << endl;
		exit(EXIT_FAILURE);
	}
}
void showCharacter(int character_physical_defence, int character_physical_attack, int character_magic_defence, int character_magic_attack, int character_life)
{
	using std::cout;
	using std::endl;
	cout << "***** FIZYCZNE *****" << endl;
	cout << "Obrona: " << character_physical_defence << endl;
	cout << "Atak: " << character_physical_attack << endl;
	cout << "***** MAGICZNE *****" << endl;
	cout << "Obrona: " << character_magic_defence << endl;
	cout << "Atak: " << character_magic_attack << endl;
	cout << "***** ZYCIE: " << character_life << " *****" << endl << endl;
}
void showCharacter(std::string character_name, int character_physical_defence, int character_physical_attack, int character_magic_defence, int character_magic_attack, int character_life)
{
	using std::cout;
	using std::endl;
	cout << "Utworzyles nastepujaca postac: " << endl;
	cout << "Imie: " << character_name << endl;
	cout << "***** FIZYCZNE *****" << endl;
	cout << "Obrona: " << character_physical_defence << endl;
	cout << "Atak: " << character_physical_attack << endl;
	cout << "***** MAGICZNE *****" << endl;
	cout << "Obrona: " << character_magic_defence << endl;
	cout << "Atak: " << character_magic_attack << endl;
	cout << "***** ZYCIE: " << character_life << " *****" << endl << endl;

}
double randDouble(double min, double max)
{
	srand(time(0));
	double number = (double)rand() / RAND_MAX;
	return min + number * (max - min);
}
int randInt(int min, int max)
{
	int number = (rand() % max) + min;
	return number; 
}

void createMonster(int &monster_physical_defence, int &monster_physical_attack, int &monster_magic_defence, int &monster_magic_attack, int &monster_life, int max_points)
{
	double average_value = 15 / 5;
	monster_physical_defence = (int)(randDouble(-15 / 6, 1) + average_value);
	monster_physical_attack = (int)(randDouble(-15 / 10, 15 / 5 - 15 / 12) + average_value);
	monster_magic_defence = (int)(randDouble(-15 / 10, 15 / 5 - 15 / 10) + average_value);
	monster_magic_attack = (int)(randDouble(-15 / 10, 0.5) + average_value);
	int amount_of_points = monster_physical_defence + monster_physical_attack + monster_magic_defence + monster_magic_attack;
	int rest_of_points = max_points - amount_of_points;
	//monster_life = 2 * rest_of_points;
	 monster_life = rest_of_points;
	/*std::cout << character_physical_defence << std::endl;
	std::cout << character_physical_attack << std::endl;
	std::cout << character_magic_defence << std::endl;
	std::cout << character_magic_attack << std::endl;
	std::cout << amount_of_points << std::endl; */
} 

void monsterAttack(int character_physical_defence, int character_magic_defence, int &character_life, int monster_physical_attack, int monster_magic_attack)
{
	int kind_of_attack = randInt(1, 2);
	int total_monster_physical_attack;
	int total_character_physical_defence;
	int total_monster_magic_attack;
	int total_character_magic_defence;
	int injuries;
	if (kind_of_attack == 1)
	{
		total_monster_physical_attack = monster_physical_attack + (int)randDouble(0, monster_physical_attack / 2);
		total_character_physical_defence = character_physical_defence + (int)randDouble(0, character_physical_defence / 2);
		injuries =total_monster_physical_attack - total_character_physical_defence;
		//std::cout << "*********\ntotal_monster_physical_attack: " << total_monster_physical_attack << std::endl << "total_character_physical_defence: " << total_character_physical_defence << "\n*********" << std::endl;

		std::cout << "Wrog wykonuje atak fizyczny. ";
	}
	else
	{
		total_monster_magic_attack = monster_magic_attack + (int)randDouble(0, monster_magic_attack / 2);
		total_character_magic_defence = character_magic_defence + (int)randDouble(0, character_magic_defence / 2);
		injuries =total_monster_magic_attack - total_character_magic_defence;
		//std::cout << "*********\ntotal_monster_magic_attack: " << total_monster_magic_attack << std::endl << "total_character_magic_defence: " << total_character_magic_defence << "\n*********" << std::endl;
		std::cout << "Wrog wykonuje atak magiczny. ";
	}
	if (injuries < 0)
		injuries = 0;
	character_life -= injuries;
	std::cout << "Obrazenia wynosza : " << injuries << "\tpozostale zycie: " << character_life << std::endl;
}
void characterAttack(int character_physical_attack, int character_magic_attack, int monster_physical_defence, int monster_magic_defence, int &monster_life)
{
	std::cout << "Wybierz rodzaj ataku (1 - fizyczny, 2 - magiczny)   ";
	int kind_of_attack;
	std::cin >> kind_of_attack;
	while (kind_of_attack != 1 && kind_of_attack != 2)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Nieprawidlowe dane! Mozesz wpisac tylko 1 lub 2. Sprobuj ponownie.  ";
		std::cin >> kind_of_attack;
	}
	int total_monster_physical_defence;
	int total_character_physical_attack;
	int total_monster_magic_defence;
	int total_character_magic_attack;
	int injuries;
	if (kind_of_attack == 1)
	{
		total_monster_physical_defence = monster_physical_defence + (int)randDouble(0, monster_physical_defence / 2);
		total_character_physical_attack = character_physical_attack + (int)randDouble(0, character_physical_attack / 2);
		injuries = total_character_physical_attack - total_monster_physical_defence;
		//std::cout << "*********\ntotal_monster_physical_defence: " << total_monster_physical_defence << std::endl << "total_character_physical_attack: " << total_character_physical_attack <<"\n*********"<< std::endl;
		std::cout << "Wykonujesz atak fizyczny ";
	}
	else
	{
		total_monster_magic_defence = monster_magic_defence + (int)randDouble(0, monster_magic_defence / 2);
		total_character_magic_attack = character_magic_attack + (int)randDouble(0, character_magic_attack / 2);
		injuries = total_character_magic_attack - total_monster_magic_defence;
		//std::cout << "*********\ntotal_monster_magic_defence: " << total_monster_magic_defence << std::endl << "total_character_magic_attack: " << total_character_magic_attack <<"\n*********"<< std::endl;
		std::cout << "Wykonujesz atak magiczny ";
	}
	if (injuries < 0)
		injuries = 0;
	monster_life -= injuries;
	std::cout << "i zadajesz obrazenia: " << injuries << "\tpozostale zycie wroga: " << monster_life << std::endl;
	

}
void createStatistics(int ***statistic, int monster_physical_defence, int monster_physical_attack, int monster_magic_defence, int monster_magic_attack, int monster_initial_life, int counter)
{
	if (counter == 1)
		*statistic = (int**)malloc(counter * sizeof(int*));
	else
		*statistic = (int**)realloc(*statistic, counter * sizeof(int*));

	(*statistic)[counter - 1] = (int*)malloc(AMOUNT_OF_ATRIBUTS * sizeof(int));
	(*statistic)[counter - 1][0] = monster_physical_defence;
	(*statistic)[counter - 1][1] = monster_physical_attack;
	(*statistic)[counter - 1][2] = monster_magic_defence;
	(*statistic)[counter - 1][3] = monster_magic_attack;
	(*statistic)[counter - 1][4] = monster_initial_life;
}
void showStatistics(int **statistic, int counter)
{
	std::cout << "Count monsters: " << counter << std::endl;
	std::cout << "***** FIZYCZNE *****" << std::endl;
	std::cout << "Obrona: " << statistic[counter - 1][0] << std::endl;
	std::cout << "Atak: " << statistic[counter - 1][1] << std::endl;
	std::cout << "***** MAGICZNE *****" << std::endl;
	std::cout << "Obrona: " << statistic[counter - 1][2] << std::endl;
	std::cout << "Atak: " << statistic[counter - 1][3] << std::endl;
	std::cout << "***** ZYCIE: "<< statistic[counter-1][4] << " *****" << std::endl << std::endl;

}
void addPoint(int &character_physical_defence, int &character_physical_attack, int &character_magic_defence, int &character_magic_attack, int &character_life)
{
	using std::cout;
	using std::endl;
	using std::cin;
	cout << "Ktory atrybut chcesz zwiekszyc? (wpisz odpowiednia cyfre)" << endl;
	cout << "0 - obrona fizyczna" << endl;
	cout << "1 - atak fizyczny" << endl;
	cout << "2 - obrona magiczna" << endl;
	cout << "3 - atak magiczny" << endl;
	cout << "4 - zycie" << endl;
	int point;
	cin >> point;
	while (point < 0 || point > 4)
	{
		cout << "Niepoprawne dane! Mozesz wpisac liczbe tylko z zakresu 0-4. Sprobuj ponownie." << endl;
		cin >> point;
	}
	switch (point)
	{
	case 0: character_physical_defence++;
		cout << "Pomyslnie dodales punkt do obrony fizycznej!" << endl;
		break;
	case 1: character_physical_attack++;
		cout << "Pomyslnie dodales punkt do ataku fizycznego!" << endl;
		break;
	case 2: character_magic_defence++;
		cout << "Pomyslnie dodales punkt do obrony magicznej!" << endl;
		break;
	case 3: character_magic_attack++;
		cout << "Pomyslnie dodales punkt do ataku magicznego!" << endl;
		break;
	case 4: character_life++;
		cout << "Pomyslnie dodales punkt do zycia!" << endl;
		break;
	}

}
void showMonstersList(int **statistic, int counter)
{
	using std::cout;
	using std::endl;
	cout << "ID        Fizyczne        Magiczne        zycie" << endl;
	cout << "          atak    obrona  atak    obrona" << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << i + 1 << "          ";
		for (int j = 0; j < AMOUNT_OF_ATRIBUTS; j++)
			cout << statistic[i][j] << "       ";
		cout << endl;
		
	}

}
void clearStatistics(int ***statistic, int counter)
{
	for (int i = 0; i < counter; i++)
		free((*statistic)[i]);
	free(*statistic);
}