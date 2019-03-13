#pragma once
#include "Mebel.h"

class Lozko: virtual public Mebel
{
public:

	Lozko() {}
	Lozko(int spanie): m_spanie(spanie) {}
	Lozko(int szer, int wys, int dl, int spanie): Mebel(szer, wys, dl), m_spanie(spanie) {}
	void print() const;
	~Lozko();

protected:
	int m_spanie;
};

void Lozko::print() const
{
	std::cout << "Lozko: ";
	Mebel::print();
	std::cout << "sz_spania: " << m_spanie;
}

Lozko::~Lozko()
{
	std::cout << "~Lozko\n";
}