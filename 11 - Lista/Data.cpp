#include "Data.h"

#include <iostream>

void IntData::print() const
{
    std::cout << " " << m_value << " ";
}
IntData* IntData::clone() const
{
    IntData* temp = new IntData(m_value);
    return temp;
}

bool IntData::compare(const Data* cmp) const
{
    const IntData* temp = dynamic_cast<const IntData*>(cmp);
    if(temp==NULL)
        return false;
    if(temp->m_value != m_value)
        return false;

    return true;
}


void StringData::print() const
{
    std::cout << " " << m_value << " ";
}
StringData* StringData::clone() const
{
    StringData* temp = new StringData(m_value);
    return temp;
}

bool StringData::compare(const Data* cmp) const
{
    const StringData* temp = dynamic_cast<const StringData*>(cmp);
    if(temp==NULL)
        return false;

    if(temp->m_value != m_value)
        return false;

    return true;
}


void FloatData::print() const
{
    std::cout << " " << m_value << " ";
}
FloatData* FloatData::clone() const
{
    FloatData* temp = new FloatData(m_value);
    return temp;
}

bool FloatData::compare(const Data* cmp) const
{
    const FloatData* temp = dynamic_cast<const FloatData*>(cmp);
    if(temp==NULL)
        return false;

    if(temp->m_value != m_value)
        return false;

    return true;
}