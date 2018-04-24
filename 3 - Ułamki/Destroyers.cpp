//
// Created by magda on 24.02.2018.
//
#include "Creators.h"

extern FractionArray fract_array;

void clear()
{
    for(int i = 0; i < fract_array.size; i++)
    {
        delete fract_array.arr[i];
    }

    delete []fract_array.arr;
}

