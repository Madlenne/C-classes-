//
// Created by magda on 24.02.2018.
//

#ifndef INC_3_CREATORS_H
#define INC_3_CREATORS_H

#include "Creators.h"
#include "Destroyers.h"

struct Fraction
{
    int numerator;
    int denominator;
};

struct FractionArray
{
    Fraction **arr;
    int size;
} ;

void Print(const Fraction *frac);
Fraction* CreateFraction (const int up, const int down);
Fraction* Sum (const Fraction* first, const Fraction* second);
Fraction* Difference(const Fraction* first, const Fraction* second);
Fraction* Product(const Fraction* first, const Fraction* second);



#endif //INC_3_CREATORS_H
