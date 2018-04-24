#include "gierka.h"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::string;
	string my_name;
	int my_all_points = 20;
	int my_physical_defence;
	int my_physical_attack;
	int my_magic_defence;
	int my_magic_attack;
	int my_life;
	setName(my_name);
	cout << endl;
	setPoints(my_physical_defence, my_physical_attack, my_magic_defence, my_magic_attack, my_life, my_all_points);
	int my_initial_life = my_life;
	cout << endl;
	showCharacter(my_name, my_physical_defence, my_physical_attack, my_magic_defence, my_magic_attack, my_initial_life);
	int monster_all_points = 15;
	int monster_physical_defence;
	int monster_physical_attack;
	int monster_magic_defence;
	int monster_magic_attack;
	int monster_life;
	int **statistics;
	int count_monsters = 0;

	while (my_life > 0)
	{
		count_monsters++;
		createMonster(monster_physical_defence, monster_physical_attack, monster_magic_defence, monster_magic_attack, monster_life, monster_all_points + POWERUP*count_monsters);
		int monster_initial_life = monster_life;
		createStatistics(&statistics, monster_physical_defence, monster_physical_attack, monster_magic_defence, monster_magic_attack, monster_initial_life, count_monsters);
		cout << "***** Atakuje Cie potwor, ktorego zycie wynosi: " << monster_life << " *****" << endl;
		while (monster_life > 0)
		{
			monsterAttack(my_physical_defence, my_magic_defence, my_life, monster_physical_attack, monster_magic_attack);
			if (my_life <= 0)
				break;
			characterAttack(my_physical_attack, my_magic_attack, monster_physical_defence, monster_magic_defence, monster_life);
			cout << "\n$$$$$ NOWA TURA $$$$$" << endl;
			if (monster_life <= 0)
			{
				/*if (count_monsters == 1)
					statistics =(int**) malloc(count_monsters * sizeof(int*));
				else
					statistics = (int**)realloc(statistics, count_monsters * sizeof(int*));
				statistics[count_monsters - 1] = (int*)malloc(AMOUNT_OF_ATRIBUTS * sizeof(int));
				statistics[count_monsters - 1][0] = monster_physical_defence;
				statistics[count_monsters - 1][1] = monster_physical_attack;
				statistics[count_monsters - 1][2] = monster_magic_defence;
				statistics[count_monsters - 1][3] = monster_magic_attack; */
				cout << "Count+monsters: " << count_monsters << endl;
				cout << "Gratulacje, pokonales potwora! Jego statystyki sa nastepujace: " << endl << endl;
				showStatistics(statistics, count_monsters);
				cout << "W nagrode mozesz zwiekszyc jeden ze swoich atrybutow o 1" << endl;
				addPoint(my_physical_defence, my_physical_attack, my_magic_defence, my_magic_attack, my_life);

			}
		}
	}
	cout << "************************************************" << endl;
	cout << "************ UMIERASZ W MECZARNIACH ************" << endl;
	cout << "************************************************" << endl << endl;
	cout << "Pokonal Cie potwor o nastepujacych statystykach: " << endl << endl;
	showStatistics(statistics, count_monsters);
	cout << endl;
	cout << "Statystyki Twojego bohatera o imieniu: " << my_name << endl;
	showCharacter(my_physical_defence, my_physical_attack, my_magic_defence, my_magic_attack, my_initial_life);
	cout << "Pokonales nastepujace potwory: " << endl;
	showMonstersList(statistics, count_monsters);
	clearStatistics(&statistics, count_monsters);

	//createMonster(monster_physical_defence, monster_physical_attack, monster_magic_defence, monster_magic_attack, monster_life, monster_all_points);
	//cout << "***** Atakuje Cie potwor, ktorego zycie wynosi: " << monster_life << " *****" << endl;
	//characterAttack(my_physical_attack, my_magic_attack, monster_physical_defence, monster_magic_defence, monster_life);
}