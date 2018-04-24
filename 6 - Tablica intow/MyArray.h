//
// Created by magda on 25.02.2018.
//

#ifndef INC_6_TABLICA_INTOW_MYARRAY_H
#define INC_6_TABLICA_INTOW_MYARRAY_H


class MyArray {

public:
    const int size;
    MyArray(const int _size=0);
    MyArray(const MyArray &copy);
    int& at(int index) const;
    void print() const;
    void resize(const int _size);

private:

    int *arr;
};


#endif //INC_6_TABLICA_INTOW_MYARRAY_H
