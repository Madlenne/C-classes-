#include "main.h"

#include <iostream>

int main()
{
    Fraction * first = CreateFraction (1,2);
    Print(first);

    Fraction * second = CreateFraction(5,3);
    Print(second);     // 1 2/3

    Fraction * sumFirstSecond = Sum (first, second);
    Print (sumFirstSecond); // 2 1/6

    Fraction * diffFirstSecond = Difference(first, second);
    Print (diffFirstSecond); // -1 1/6

    Fraction * prodFirstSecond = Product(first, second);
    Print(prodFirstSecond); // 5/6

    clear();

    return 0;
}