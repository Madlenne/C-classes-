#include "Magia.h"
#include <iostream>

static int how_many = 0;

void UtworzCzar(const Czary text, Czary* start, Czary* end)
{
	int i = 0;
	//int length = 0;

	while (text[i++]);
		//length++;

	*start = new char[i];
	*end = *start + i-1;

	for (int j = 0; j < i; j++)
		(*start)[j] = text[j];

}

void RzucCzar(Czary start, Czary end)
{
	int rozmiar = end-start;
	/*int i = 0;
	while (start <= end)
	{
		std::cout << start[i];
		start++;
	} */
	for (int i = 0; i < rozmiar; i++)
		std::cout << start[i];

	std::cout << std::endl;

}

void DodajCzar(KsiegaCzarow* book, Czary start, Czary end)
{
	int length = end - start;
	static bool if_first = true;

	if (if_first)
	{
		*book = new char*[1];
		//(*book)[0] = start;
		(*book)[how_many] = new char[length + 1];

		for (int i = 0; i < length; i++)
			(*book)[how_many][i] = start[i];

		(*book)[how_many][length] = '\0'; 
		
		how_many++;
		if_first = false;
	}

	else
	{
		int j = 0;
		int length = 0;
		KsiegaCzarow temp = new char*[how_many];

		for (int i = 0; i < how_many; i++)
		{
			j = 0;
		    length = 0;
			while ((*book)[i][j] != '\0')
			{
				length++;
				j++;
			}
				
			temp[i] = new char[length + 1];

			j = 0;

			while (j<=length)
			{
				temp[i][j] = (*book)[i][j];
				j++;
			}
			//std::cout << "***********\n" << temp[i];
		}

		for (int i = 0; i < how_many; i++)
			delete (*book)[i];
		
		delete[] *book;

		how_many++;

		*book = new char*[how_many];

		for (int i = 0; i < how_many - 1; i++)
		{
			j = 0;
			length = 0;
			while (temp[i][j] != '\0')
			{
				length++;
				j++;
			}

			(*book)[i] = new char[length + 1];

			j = 0;

			while (j <= length)
			{
				(*book)[i][j] = temp[i][j];
				j++;
			}
		}

		int length2 = end - start;

		(*book)[how_many - 1] = new char[length2];

		for (int i = 0; i < length2; i++)
			(*book)[how_many - 1][i] = start[i];

		(*book)[how_many - 1][length2] = '\0';

	} 

	/*else
	{
		KsiegaCzarow temp = new char*[how_many];

		for (int i = 0; i < how_many; i++)
			temp[i] = (*book)[i];
		std::cout << "********** temp[0] = \n" << temp[0] << std::endl;
		//for (int i = 0; i < how_many; i++)
			//delete[](*book)[i];

		delete[](*book)[0];

		delete[] * book;

		*book = new char*[how_many + 1];

		//for (int i = 0; i < how_many; i++)
			//(*book)[i] = temp[i];
		(*book)[0] = temp[0];
		std::cout << "********** (*book)[i] = \n" << (*book)[0] << std::endl;
		std::cout << "********** temp[0] = \n" << temp[0] << std::endl;
		(*book)[how_many++] = start;

	} */
}
void Czytaj(KsiegaCzarow* book)
{
	std::cout << std::endl;
	std::cout << "KSIEGA CZAROW: " << std::endl;

	for (int i = 0; i < how_many; i++)
		std::cout << (*book)[i] << std::endl;

}

void SpalKsiege(KsiegaCzarow book)
{
	//for (int i = 0; i < how_many; i++)
		//delete[] book[i];

	delete *book;

}

void ZniszczCzar(Czary start, Czary end)
{
	delete start;
	end = 0;
}