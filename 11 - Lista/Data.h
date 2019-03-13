#pragma once
#include <string>
#include <iostream>

class Data{
public:
    
    virtual void print() const=0;
    virtual Data* clone()const=0;
    virtual bool compare(const Data* cmp)const=0;
    Data* get(){return next;}
    void set(Data* new_data){next=new_data;}
    virtual ~Data() {}

private:
    Data* next;
};

class IntData: public Data{
public:

    IntData(int value=0):m_value(value) {}
    IntData* clone()const;
    bool compare(const Data* cmp)const;
    void print() const;
    virtual ~IntData() {std::cout << "~IntData()\n";}

private:
    int m_value;

};

class StringData: public Data{
public:

    StringData(std::string value=" "):m_value(value) {}
    StringData* clone()const;
    bool compare(const Data* cmp)const;
    void print() const;
    virtual ~StringData() {std::cout << "~StringData()\n";}

private:
    std::string m_value;

};

class FloatData: public Data{
public:

    FloatData(float value=0.0):m_value(value)
    {
        
    }
    FloatData* clone()const;
    bool compare(const Data* cmp)const;
    void print() const;
    virtual ~FloatData() {std::cout << "~FloatData()\n";}

private:
    float m_value;

};
