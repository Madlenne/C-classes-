#pragma once

class Punkt
{
public:
	Punkt(): m_x(0), m_y(0){}
	Punkt(const int x, const int y): m_x(x), m_y(y) {}
	template <int coordinate> int wsp() const;
	bool operator<(const Punkt& to_compare) const;
	~Punkt() {} 

	template<typename T>
	static const T min(const T first, const T second);

	template<typename T>
	static const T max(const T first, const T second);

private:
	const int m_x, m_y;

};

template <int coordinate>
int Punkt::wsp() const
{
	if(coordinate)
		return m_y;
	return m_x;
}

bool Punkt::operator<(const Punkt& to_compare) const
{
	if(m_x == to_compare.m_x)
		return m_y < to_compare.m_y;
	return m_x < to_compare.m_x;
}

template<typename T>
const T Punkt::min(const T first, const T second)
{
	if(first < second)
		return first;
	return second;
}

template<typename T>
const T Punkt::max(const T first, const T second)
{
	if(first < second)
		return second;
	return first;
}