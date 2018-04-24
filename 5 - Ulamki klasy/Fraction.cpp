//
// Created by magda on 25.02.2018.
//

#include "Fraction.h"

#include <iostream>



Fraction::Fraction(int up, int down)
{
    m_numerator = up;
    m_denominator = down;
}
void Fraction::Print() const
{
    int whole_part=0;
   int fract_part = m_numerator % m_denominator;

    if(m_numerator >= m_denominator || m_numerator*(-1) >= m_denominator)
    {
        whole_part=m_numerator / m_denominator;
    }

    if(whole_part)
        std::cout << whole_part << " ";

    if(m_numerator<0)
        std::cout << fract_part*(-1);
    else
        std::cout << fract_part;

    std::cout  << "/" <<  m_denominator << std::endl;
}
void Fraction::Add(const Fraction &second)
{
    m_numerator=m_numerator*second.m_denominator+m_denominator*second.m_numerator;
    m_denominator*=second.m_denominator;
}
void Fraction::SetValue(int up, int down)
{
    m_numerator=up;
    m_denominator=down;
}

int Fraction::get()
{
    return m_denominator;
}
