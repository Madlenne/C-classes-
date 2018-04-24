//
// Created by magda on 25.02.2018.
//

#ifndef INC_5_UAMKI_KLASY_FRACTION_H
#define INC_5_UAMKI_KLASY_FRACTION_H

class Fraction
{
public:
    Fraction(int up, int down);
    void Print() const;
    void Add(const Fraction &second);
    void SetValue(int up, int down);
    int get();

private:

    Fraction();
    int m_numerator;
    int m_denominator;
};

#endif //INC_5_UAMKI_KLASY_FRACTION_H
