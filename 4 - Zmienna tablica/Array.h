//
// Created by magda on 24.02.2018.
//

#ifndef INC_4_ZMIENNA_TABLICA_ARRAY_H
#define INC_4_ZMIENNA_TABLICA_ARRAY_H

#include <iostream>

struct Array
{
    int **arr;
    int *columns;
    int rows;
};

void CreateArray (Array * &first, const int *columns_arr, const int row);

void FillWith(Array *first, int number);

void Print (Array first);

void SetElement(int row, int column, Array** first, int number);

void PrintMax (Array* first);

void Clear (Array** first);

#endif //INC_4_ZMIENNA_TABLICA_ARRAY_H
