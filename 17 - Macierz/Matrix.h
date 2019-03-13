#pragma once
#include <iostream>

template<typename T, int rows, int columns>
class Matrix
{
public:
	Matrix();
	void reset(T value);


	template<typename U>
	void add(const Matrix<U, rows, columns>& to_add)
	{
		for(int i = 0; i < rows; ++i)
			for(int j = 0; j < columns; ++j)
				m_matrix[i][j] += to_add.m_matrix[i][j];
	}

	template<int row, int column>
	T& at() { return m_matrix[row][column];}

	template<typename, int, int> 
	friend class Matrix;

	friend std::ostream& operator<<(std::ostream& os, const Matrix<T,rows, columns>& to_print)
	{
		for(int i = 0; i < rows; ++i)
			{
				for(int j = 0; j < columns; ++j)
				os << to_print.m_matrix[i][j] << " ";
				os << std::endl;
			}

			return os;
	}

private:
	T m_matrix[rows][columns];

};


template<typename T, int rows, int columns>
Matrix<T, rows, columns>::Matrix()
{
	for(int i = 0; i < rows; ++i)
		for(int j = 0; j < columns; ++j)
			m_matrix[i][j] = 0;
}

template<typename T, int rows, int columns>
void Matrix<T, rows, columns>::reset(T value)
{
	for(int i = 0; i < rows; ++i)
		for(int j = 0; j < columns; ++j)
			m_matrix[i][j] = value;
}

