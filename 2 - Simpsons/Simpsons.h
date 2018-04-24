//
// Created by magda on 23.02.2018.
//

#ifndef INC_2_SIMPSONS_H_H
#define INC_2_SIMPSONS_H_H

struct Student
{
    char first_letter_name;
    char first_letter_surname;
    int grade;
};

struct StudentsArray
{
    struct Student **element;
    int size;
};

struct Iterator
{
    struct Student *object;
    struct StudentsArray *ptr;
    int current;
    int how_many;

};

void print(const struct Student &person);
void set_student (const char &nletter, const char sletter, const int grade, struct Student *person);

void init_array(struct StudentsArray *arr, const int how_big);

void init_iter (struct StudentsArray *arr, struct Iterator *iter);
void move_forward(struct Iterator *iter);
void select_element(struct Iterator *iter, const int which);
void delete_array (struct StudentsArray *arr);

#endif //INC_2_SIMPSONS_H_H
