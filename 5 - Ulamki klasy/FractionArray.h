//
// Created by magda on 25.02.2018.
//

#ifndef INC_5_UAMKI_KLASY_FRACTIONARRAY_H
#define INC_5_UAMKI_KLASY_FRACTIONARRAY_H

#include "Fraction.h"

class FractionArray
{
public:
    FractionArray(int size);
    void AddFration( Fraction &second);
    void Print() const;
    Fraction Sum();

private:
    Fraction **m_arr;
    int m_size;
    int m_counter;
};

#endif //INC_5_UAMKI_KLASY_FRACTIONARRAY_H
