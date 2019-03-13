#pragma once
#include <iostream>

class Obserwator
{
public:

	virtual void odbiorDanych(int dane) = 0;

};


class ObserwatorLicznik: public Obserwator
{
public:
	ObserwatorLicznik(): m_suma(0) {}
	void odbiorDanych(int dane);
	int suma();
private:
	int m_suma;
};


class ObserwatorWypisywacz: public Obserwator
{
public:
	void odbiorDanych(int dane);

private:
	std::vector<int> m_dane;
};


void ObserwatorLicznik::odbiorDanych(int dane)
{
	m_suma += dane;
}

int ObserwatorLicznik::suma()
{
	return m_suma;
}

void ObserwatorWypisywacz::odbiorDanych(int dane)
{
	std::cout << dane << " ";
}