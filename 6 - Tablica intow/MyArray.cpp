//
// Created by magda on 25.02.2018.
//

#include "MyArray.h"
#include <iostream>

MyArray::MyArray(const int _size):size(_size)
{
    arr = new int[_size];
}

MyArray::MyArray(const MyArray &copy):size(copy.size)
{
    arr = new int[size];

    for(int i=0; i<size; i++)
        arr[i]=copy.arr[i];
}
int& MyArray::at(int index) const
{
    return arr[index];
}
void MyArray::print() const
{
    for(int i=0; i<size; i++)
        std::cout << "array[" << i << "] = " << arr[i]  << std::endl;
}
void MyArray::resize(const int _size)
{
    int temp[size];

    for (int i=0; i<size; i++)
        temp[i]=arr[i];

    delete[] arr;

    arr = new int[_size];

    for (int i=0; i<size; i++)
        arr[i] = temp[i];

    int *not_const = const_cast<int *>(&size);
    *not_const=_size;


}