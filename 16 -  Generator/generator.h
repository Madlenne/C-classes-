#pragma once

template <typename T>
class generator
{
public:
	generator(T value, T (*fun)(T value)) : m_value(value), m_old_value(value), m_fun(fun) {}
	T current() { return m_value; }
	T next();
	void reset(T value, T (*fun)(T value));
	void reset();
	void operator++();
	bool operator<(int);
	bool operator>(int);

private:
	T m_value;
	T m_old_value;
	T (*m_fun)(T value);

};

template <typename T>
T generator<T>::next() 
{ 
	m_value = m_fun(m_value); 
	return m_value; 
}

template <typename T>
void generator<T>::reset(T value, T (*fun)(T value)) 
{ 
	m_value = value;  
	m_fun = fun;
}

template <typename T>
void generator<T>::reset() 
{
	m_value = m_old_value;
}

template <typename T>
void generator<T>::operator++() 
{ 
	m_value = m_fun(m_value); 
}

template <typename T>
bool generator<T>::operator<(int to_compare)
{
	return m_value < to_compare;
}

template <typename T>
bool generator<T>::operator>(int to_compare)
{
	return m_value > to_compare;
}