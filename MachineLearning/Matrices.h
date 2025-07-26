#pragma once
#include "global.h"

template<size_t size, Numeric Number>
class Matrix
{
public:
	Matrix()
	{
		for (auto& row : m_matrix)
			row.fill(zero_init<Number>());
	}

	Matrix(std::initializer_list<std::initializer_list<Number>> init) noexcept
	{
		size_t i = 0;
		for (const auto& row : init) 
		{
			size_t j = 0;
			for (const auto& val : row) 
			{
				if (i < size && j < size) 
				{
					m_matrix[i][j] = val;
					j++;
				}
			}
			i++;
		}
	}
public:
	Matrix operator+(const Matrix& other) const noexcept
	{
		Matrix result;
		for (size_t i = 0; i < size; ++i) 
		{
			for (size_t j = 0; j < size; ++j)
			{
				result(i, j) = (*this)(i, j) + other(i, j);
			}
		}
		return result;
	}

	Matrix operator+(Number scalar) const noexcept
	{
		Matrix result;
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = 0; j < size; ++j)
			{
				result(i, j) = (*this)(i, j) + scalar;
			}
		}
		return result;
	}
public:
	Matrix operator-(const Matrix& other) const noexcept
	{
		Matrix result;
		for (size_t i = 0; i < size; ++i) 
		{
			for (size_t j = 0; j < size; ++j)
			{
				result(i, j) = (*this)(i, j) - other(i, j);
			}
		}
		return result;
	}

	Matrix operator-(Number scalar) const noexcept
	{
		Matrix result;
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = 0; j < size; ++j)
			{
				result(i, j) = (*this)(i, j) - scalar;
			}
		}
		return result;
	}

public:
	Matrix operator*(Number scalar) const noexcept
	{
		Matrix result;
		for (size_t i = 0; i < size; ++i)
		{
			for (size_t j = 0; j < size; ++j)
			{
				result(i, j) = (*this)(i, j) * scalar;
			}
		}
		return result;
	}
	Matrix operator*(const Matrix& other) const noexcept
	{
		Matrix result;

		if constexpr (size == 2) 
		{
			// Optimized 2×2 matrix multiplication (4 multiplications + 8 additions)
			const auto& a = *this;
			const auto& b = other;
			result(0, 0) = a(0, 0) * b(0, 0) + a(0, 1) * b(1, 0);
			result(0, 1) = a(0, 0) * b(0, 1) + a(0, 1) * b(1, 1);
			result(1, 0) = a(1, 0) * b(0, 0) + a(1, 1) * b(1, 0);
			result(1, 1) = a(1, 0) * b(0, 1) + a(1, 1) * b(1, 1);
		}
		else if constexpr (size == 3) 
		{
			// Optimized 3×3 matrix multiplication (27 multiplications + 18 additions)
			const auto& a = *this;
			const auto& b = other;
			for (size_t i = 0; i < 3; ++i) {
				result(i, 0) = a(i, 0) * b(0, 0) + a(i, 1) * b(1, 0) + a(i, 2) * b(2, 0);
				result(i, 1) = a(i, 0) * b(0, 1) + a(i, 1) * b(1, 1) + a(i, 2) * b(2, 1);
				result(i, 2) = a(i, 0) * b(0, 2) + a(i, 1) * b(1, 2) + a(i, 2) * b(2, 2);
			}
		}
		else if constexpr (size == 4) 
		{
			// Optimized 4×4 matrix multiplication (64 multiplications + 48 additions)
			const auto& a = *this;
			const auto& b = other;
			for (size_t i = 0; i < 4; ++i) 
			{
				result(i, 0) = a(i, 0) * b(0, 0) + a(i, 1) * b(1, 0) + a(i, 2) * b(2, 0) + a(i, 3) * b(3, 0);
				result(i, 1) = a(i, 0) * b(0, 1) + a(i, 1) * b(1, 1) + a(i, 2) * b(2, 1) + a(i, 3) * b(3, 1);
				result(i, 2) = a(i, 0) * b(0, 2) + a(i, 1) * b(1, 2) + a(i, 2) * b(2, 2) + a(i, 3) * b(3, 2);
				result(i, 3) = a(i, 0) * b(0, 3) + a(i, 1) * b(1, 3) + a(i, 2) * b(2, 3) + a(i, 3) * b(3, 3);
			}
		}


		return result;
	}
public:
	// Access element (non-const)
	Number& operator()(size_t row, size_t col) 
	{
		return m_matrix[row][col];
	}

	// Access element (const)
	const Number& operator()(size_t row, size_t col) const 
	{
		return m_matrix[row][col];
	}


private:
	std::array<std::array<Number, size>, size> m_matrix;
};



using Matrix2dl = Matrix<2, long>;
using Matrix3dl = Matrix<3, long>;
using Matrix4dl = Matrix<4, long>;

using Matrix2di = Matrix<2, int>;
using Matrix3di = Matrix<3, int>;
using Matrix4di = Matrix<4, int>;

using Matrix2df = Matrix<2, float>;
using Matrix3df = Matrix<3, float>;
using Matrix4df = Matrix<4, float>;

using Matrix2dd = Matrix<2, double>;
using Matrix3dd = Matrix<3, double>;
using Matrix4dd = Matrix<4, double>;

template<size_t size, typename Number>
void printMatrix(const Matrix<size, Number>& matrix) 
{
	for (size_t i = 0; i < size; ++i) 
	{
		for (size_t j = 0; j < size; ++j) 
		{
			std::print("{} ", matrix(i, j));
		}
		std::println();
	}
}
