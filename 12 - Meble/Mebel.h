#pragma once
#include <iostream>

class Mebel
{
public:

	Mebel() {}
	Mebel(int szer, int wys, int dl): m_szer(szer), m_wys(wys), m_dl(dl) {}
	virtual void print() const;
	virtual ~Mebel();

protected:
	int m_szer, m_wys, m_dl;
};

void Mebel::print() const
{
	std::cout << "Mebel: sz:" << m_szer << " wys: " << m_wys << " dl: " << m_dl << " ";
}


Mebel::~Mebel()
{
	std::cout << "~Mebel\n";
}

std::ostream& operator<<(std::ostream& os, const Mebel& to_print)
{
	to_print.print();
	return os;
}
