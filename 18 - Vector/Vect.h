#pragma once
#include <string.h>
#include <iostream>

template<typename T>
struct is_pod
{
	const static bool value = false;
};

template <typename T, bool pod>
struct swap
{
	static void copy(T* first, T* second)
	{
		T temp_obj;
		temp_obj = *second;
		*second = *first;
		*first = temp_obj;
	}
};

template <typename T>
struct swap<T, true>
{
	static void copy(T* first, T* second)
	{
		T* temp_obj = new T;
		memcpy(temp_obj, second, sizeof(T));
		memcpy(second, first, sizeof(T));
		memcpy(first, temp_obj, sizeof(T));
		delete temp_obj;
	}
};



template <typename T>
class Vect
{
public:
	Vect(int size = 0): m_size(size) { m_array = new T[m_size]; }
	T& operator[](int index) { return m_array[index]; }
	int size() { return m_size; }
	void buble_sort(bool (*comparator)(const T& first, const T& second));

private:
	T* m_array;
	int m_size;
};


template <typename T>
void Vect<T>::buble_sort(bool (*comparator)(const T& first, const T& second))
{
	for(int i = 0; i < m_size; ++i)
		for(int j = i+1; j < m_size; ++j)
			if(comparator(m_array[i], m_array[j]))
				swap<T, is_pod<T>::value>::copy(&m_array[j], &m_array[i]);
}