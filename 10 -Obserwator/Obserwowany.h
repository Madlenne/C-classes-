#pragma once
#include <vector>
#include "Obserwator.h"

class Obserwowany
{
public:

	virtual void noweDaneNadeszly(int dane);
	virtual void dodajObserwatora(Obserwator* obs);

private:
	std::vector<Obserwator*> m_dane;
};

void Obserwowany::noweDaneNadeszly(int dane)
{
	for(std::vector<Obserwator*>::iterator it = m_dane.begin(); it != m_dane.end(); ++it)
		(*it)->odbiorDanych(dane);
}


void Obserwowany::dodajObserwatora(Obserwator* obs)
{
	m_dane.push_back(obs);
}