#pragma once
#define AMOUNT_OF_ATRIBUTS 5
#define POWERUP 5
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
void setName (std::string &character_name);
void setPoints(int &character_physical_defence, int &character_physical_attack, int &character_magic_defence, int &character_magic_attack, int &character_life, int amount_of_points);
void showCharacter(int character_physical_defence, int character_physical_attack, int character_magic_defence, int character_magic_attack, int character_life);
void showCharacter(std::string character_name, int character_physical_defence, int character_physical_attack, int character_magic_defence, int character_magic_attack, int character_life);
void createMonster(int &character_physical_defence, int &character_physical_attack, int &character_magic_defence, int &character_magic_attack, int &character_life, int max_points);
double randDouble(double min, double max);
void monsterAttack(int character_physical_defence, int character_magic_defence, int &character_life, int monster_physical_attack, int monster_magic_attack);
void characterAttack(int character_physical_attack, int character_magic_attack, int monster_physical_defence, int monster_magic_defence, int &monster_life);
void createStatistics(int ***statistic, int monster_physical_defence, int monster_physical_attack, int monster_magic_defence, int monster_magic_attack, int monster_initial_life, int counter);
void showStatistics(int **statistic, int counter);
void addPoint(int &character_physical_defence, int &character_physical_attack, int &character_magic_defence, int &character_magic_attack, int &character_life);
void showMonstersList(int **statistic, int counter);
void clearStatistics(int ***statistic, int counter);
