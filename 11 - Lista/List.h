#pragma once
#include "Data.h"

class List
{
public:
    List();
    List(List& copy);
    List& insert (const Data& new_data, int where = List::End);
    void print() const;
    bool find(const Data& find_data);
    ~List();

    static const int Begin=1;
    static const int End=0;

private:
    Data *m_begin;
    Data *m_end;

};
