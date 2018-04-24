//
// Created by magda on 23.02.2018.

#include "Simpsons.h"
#include <iostream>

void print(const struct Student &person)
{
    std::cout << "Initials: " << person.first_letter_name << ". " << person.first_letter_surname << "  grade: " << person.grade << std::endl;
}
void set_student (const char &nletter, const char sletter, const int gr, struct Student *person)
{
    person->first_letter_name=nletter;
    person->first_letter_surname=sletter;
    person->grade=gr;

}

void init_array(struct StudentsArray *arr, const int how_big)
{
    arr->element=new Student*[how_big];
    arr->size=how_big;
}

void init_iter (struct StudentsArray *arr, struct Iterator *iter)
{
    iter->object=arr->element[0];
    iter->current=0;
    iter->how_many=arr->size;
    iter->ptr=arr;

}
void move_forward(struct Iterator *iter)
{
    if(iter->current+1 >= iter->ptr->size)
    {
        std::cout << "Index out of range.\n";
        iter->object=0;
    }
    else
    {
        iter->current++;
        iter->object=iter->ptr->element[iter->current];
    }
}
void select_element(struct Iterator *iter, const int which)
{
    if(which >= iter->ptr->size)
    {
        std::cout << "Index out of range.\n";
        iter->object=0;
    }
    else
    {
        iter->current=which;
        iter->object=iter->ptr->element[iter->current];
    }
}
void delete_array (struct StudentsArray *arr)
{
    delete arr->element;
}
//

