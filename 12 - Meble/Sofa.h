#pragma once
#include "Mebel.h"

class Sofa: virtual public Mebel
{
public:

	Sofa() {}
	Sofa(int siedzisko): m_siedzisko(siedzisko){}
	Sofa(int szer, int wys, int dl, int siedzisko): Mebel(szer, wys, dl), m_siedzisko(siedzisko) {}
	void print() const;
	~Sofa();

protected:
	int m_siedzisko;
};

void Sofa::print() const
{
	std::cout << "Sofa: ";
	Mebel::print();
	std::cout << "siedzisko: " << m_siedzisko;
}

Sofa::~Sofa()
{
	std::cout << "~Sofa\n";
}