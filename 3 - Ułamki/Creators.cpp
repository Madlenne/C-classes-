//
// Created by magda on 24.02.2018.
//

#include "Creators.h"
#include <iostream>

FractionArray fract_array={0,0};

void Print(const Fraction *frac)
{
    int whole_part=0;
    int fract_part = frac->numerator % frac->denominator;


    if(frac->numerator >= frac->denominator || frac->numerator*(-1) >= frac->denominator)
    {
        whole_part=frac->numerator / frac->denominator;
    }

    if(whole_part)
        std::cout << whole_part << " ";

    if(frac->numerator<0)
        std::cout << fract_part*(-1);
    else
        std::cout << fract_part;

   std::cout  << "/" <<  frac->denominator << std::endl;

}
Fraction* CreateFraction (const int up, const int down)
{
    if(fract_array.size==0)
    {
        fract_array.arr = new Fraction *[fract_array.size+1];
    }
    else
    {
        /*Fraction **temp_arr=new Fraction*[fract_array.size];
        for(int i = 0; i < fract_array.size; i++)
        {
            temp_arr[i]=new Fraction;
            temp_arr[i]->numerator=fract_array.arr[i]->numerator;
            temp_arr[i]->denominator=fract_array.arr[i]->denominator;
        }

        clear();
        fract_array.arr = new Fraction *[fract_array.size+1];
        for(int i = 0; i < fract_array.size; i++)
        {
            fract_array.arr[i]=new Fraction;
            fract_array.arr[i]->numerator = temp_arr[i]->numerator;
            fract_array.arr[i]->denominator = temp_arr[i]->denominator;
        } */

        Fraction *temp_arr[fract_array.size];

        for(int i = 0; i < fract_array.size; i++)
        {
            temp_arr[i]=fract_array.arr[i];
        }

        delete[] fract_array.arr;
        fract_array.arr = new Fraction *[fract_array.size+1];

        for(int i = 0; i < fract_array.size; i++)
        {
            fract_array.arr[i]=temp_arr[i];
        }

    }
    fract_array.arr[fract_array.size]=new Fraction;
    fract_array.arr[fract_array.size]->numerator = up;
    fract_array.arr[fract_array.size]->denominator = down;
    fract_array.size++;

    return fract_array.arr[fract_array.size-1];
}
Fraction* Sum (const Fraction* first, const Fraction* second)
{
    int temp_numerator;
    int temp_denumerator;

    temp_numerator=first->numerator*second->denominator+first->denominator*second->numerator;
    temp_denumerator=first->denominator*second->denominator;

    return CreateFraction(temp_numerator, temp_denumerator);
}
Fraction* Difference(const Fraction* first, const Fraction* second)
{
    int temp_numerator;
    int temp_denumerator;

    temp_numerator=first->numerator*second->denominator-first->denominator*second->numerator;
    temp_denumerator=first->denominator*second->denominator;

    return CreateFraction(temp_numerator, temp_denumerator);
}
Fraction* Product(const Fraction* first, const Fraction* second)
{
    int temp_numerator;
    int temp_denumerator;

    temp_numerator=first->numerator*second->numerator;
    temp_denumerator=first->denominator*second->denominator;


    return CreateFraction(temp_numerator, temp_denumerator);
}

