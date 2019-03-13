#pragma Kanapa
#include "Mebel.h"

class Kanapa: public Sofa, public Lozko
{
public:

	Kanapa() {}
	Kanapa(int szer, int wys, int dl, int siedzisko, int spanie): Mebel(szer, wys, dl), Sofa(siedzisko), Lozko(spanie) {}
	void print() const;
	~Kanapa();

};

void Kanapa::print() const
{
	std::cout << "\njako ";
	Mebel:: print();
	std::cout << "\njako ";
	Sofa::print();
	std::cout << "\njako ";
	Lozko::print();
}

Kanapa::~Kanapa()
{
	std::cout << "~Kanapa\n";
}