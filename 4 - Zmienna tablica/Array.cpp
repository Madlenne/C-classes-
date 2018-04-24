//
// Created by magda on 24.02.2018.
//
#include "Array.h"

void CreateArray (Array * &first, const int *columns_arr, const int row)
{
    first = new Array;
    first->arr = new int*[row];
    first->columns = new int[row];
    first->rows = row;

    for(int i = 0; i < row; i++)
        first->columns[i] = columns_arr[i];

    for(int i = 0; i < row; i++)
    {
        first->arr[i] = new int[columns_arr[i]];
        for(int j = 0; j < columns_arr[i]; j++)
            first->arr[i][j] = 0;
    }
}

void FillWith(Array *first, int number)
{
    for(int i = 0; i < first->rows; i++)
    {
        for(int j = 0; j < first->columns[i]; j++)
            first->arr[i][j] = number;
    }
}

void Print (Array first)
{
    for(int i = 0; i < first.rows; i++)
    {
        for(int j = 0; j < first.columns[i]; j++)
            std::cout << first.arr[i][j] << " ";

        std::cout << std::endl;
    }
}

void SetElement(int row, int column, Array** first, int number)
{
    if(row >= (*first)->rows || column >= (*first)->columns[row])
        std::cout << "Index out of bounds\n";
    else
    (*first)->arr[row][column]=number;
}

void PrintMax (Array* first)
{
    int max=0;
    int global_max=0;

    for(int i = 0; i < first->rows; i++)
    {
        max=0;
        for(int j = 0; j < first->columns[i]; j++)
        {
            if(first->arr[i][j] > max)
            {
                max = first->arr[i][j];
            }

        }
        std:: cout << "max " << i << ": " << max << std::endl;

        if(max > global_max)
        {
            global_max = max;
        }
    }

    std:: cout << "maximum globalne: " << global_max << std::endl;

}

void Clear (Array** first)
{
    for(int i = 0; i < (*first)->rows; i++)
    {
       delete[] (*first)->arr[i];
    }

    delete [] (*first)->arr;
    delete *first;

}