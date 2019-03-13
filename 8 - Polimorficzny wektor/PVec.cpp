#include "PVec.h"


void IntWrapper::print(std::ostream& os) const
{
	os << m_data;
}

void FloatWrapper::print(std::ostream& os) const
{
	os << m_data;
}

void StringWrapper::print(std::ostream& os) const
{
	os << m_data;
}


Wrapper& PVec::operator[](int index)
{
	return *m_data[index];
}


PVec& PVec::push_back( Wrapper* to_add)
{
	m_data.push_back(to_add);
	return *this;
}

void PVec::operator<<(Wrapper* to_add)
{
	m_data.push_back(to_add);
}

std::ostream& operator<<(std::ostream& os, const PVec& to_print)
{
	for(int i = 0; i< to_print.m_data.size(); ++i)
		{
			to_print.m_data[i]->print(os);
			os << " ";
		}

			
	return os; 
}

PVec::~PVec()
{
	for(int i = 0; i< m_data.size(); ++i)
		delete m_data[i];
}