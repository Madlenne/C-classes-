//
// Created by magda on 25.02.2018.
//

#include "FractionArray.h"
#include <iostream>
FractionArray::FractionArray(int size)
{
    m_arr = new Fraction*[size];
    m_size=size;
    m_counter=0;

}
void FractionArray::AddFration( Fraction &second)
{
    if(m_counter<m_size)
    {
      m_arr[m_counter]=&second;
        m_counter++;
    }

}
void FractionArray::Print() const
{
    for(int i=0; i<m_size;i++)
        m_arr[i]->Print();
}
Fraction FractionArray::Sum()
{
    Fraction sum(0,1);

    for(int i=0; i<m_size;i++)
        sum.Add(*(m_arr[i]));

    std::cout << "suma: \n";

    std::cout << sum.get();
    return sum;
}
