#include "List.h"

#include <iostream>
#include <typeinfo>


List::List()
{
    m_begin = NULL;
    m_end = NULL;
}
List::List(List& copy)
{
    Data *temp = copy.m_begin;
    m_begin = NULL;
    m_end = NULL;
    while(temp!=copy.m_end->get())
    {
        insert(*(temp));
        temp = temp->get();
    }

}
List& List::insert (const Data& new_data, int where)
{
    Data* temp = new_data.clone();

    if(where==List::Begin && m_begin!=NULL)
    {
        temp->set(m_begin);
        m_begin = temp;
    }
    else if(where == List::End && m_end != NULL)
    {
        m_end->set(temp);
        m_end = temp;
        m_end->set(NULL);
    }

    if(m_begin == NULL)
    {
        temp->set(NULL);
        m_begin = temp;
        m_end = temp;
    }

    return *this;
}

void List::print() const
{
    Data* temp = m_begin;
    while(temp != m_end->get())
    {
        temp->print();
        temp=temp->get();
    }
    std::cout << std::endl;
}


bool List::find(const Data& find_data)
{
    for(Data* iter = m_begin; iter!=m_end->get(); iter=iter->get())
    {
        if(iter->compare(&find_data))
            return 1;
    }
    return 0;
}

List::~List(){
    Data* temp;
    while(m_begin!=m_end->get())
    {
        temp = m_begin;
        m_begin = temp->get();
        delete temp;
    }
}

