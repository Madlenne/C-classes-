#pragma once
#include <vector>
#include <string>
#include <iostream>

class Wrapper
{
public:
	virtual void print(std::ostream& os) const = 0;
};

class IntWrapper: public Wrapper
{
public:
	IntWrapper() {}
	IntWrapper(int data): m_data(data) {}
	void print(std::ostream& os) const;

private:
	int m_data;
};


class FloatWrapper: public Wrapper
{
public:
	FloatWrapper() {}
	FloatWrapper(float data): m_data(data) {}
	void print(std::ostream& os) const;

private:
	float m_data;
};

class StringWrapper: public Wrapper
{
public:
	StringWrapper() {}
	StringWrapper(std::string data): m_data(data) {}
	void print(std::ostream& os) const;

private:
	std::string m_data;
};

class PVec
{
public:

	Wrapper& operator[](int index);
	PVec& push_back (Wrapper* to_add);
	void operator<<(Wrapper* to_add);
	~PVec();

	friend std::ostream& operator<<(std::ostream& os, const PVec& to_print);

private:
	std::vector<Wrapper*> m_data;
};


